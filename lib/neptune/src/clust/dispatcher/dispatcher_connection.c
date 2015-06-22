/*
** dispatcher_connection.c for dispatcher in /home/zack/neptune/src/clust/dispatcher
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 14:58:12 2015 Antoine Favarel
** Last update mer. juin 03 17:09:27 2015 Antoine Favarel
*/

#include	<signal.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<errno.h>
#include	"neptune/clust/dispatcher.h"

static void	send_data(t_dispatcher *this, t_socket *client)
{
  t_metadata	*meta;
  t_elem	*data;

  meta = new_metadata(MR_DATA, MD_LIST);
  data = _wrap(meta, sizeof(t_metadata));
  data->save(data, (t_io*)client);
  this->data->save(this->data, (t_io*)client);
  free(meta);
  delete_elem(data);
}

static void	send_order(t_socket *s, t_list *list, t_list *lo)
{
  t_metadata	*meta;
  t_elem	*data;
  t_elem	*elem;

  list->rewind(list);
  while ((elem = list->next(list)))
  {
    elem->id = rand();
    lo->push(lo, elem->dup(elem));
  }
  s->lock(s);
  s->counter = list->length;
  s->unlock(s);
  meta = new_metadata(MR_ORDER, MD_LIST);
  data = _wrap(meta, sizeof(t_metadata));
  s->lock(s);
  data->save(data, (t_io*)s);
  list->save(list, (t_io*)s);
  s->unlock(s);
  delete_list(list);
  free(meta);
  delete_elem(data);
}

static void	st_loop(t_dispatcher *this, t_socket *client, t_list *lo)
{
  t_list	*list;
  t_timespec	ts;

  while (client->is_assync)
    while ((list = this->orders->popretto(this->orders, 1500)))
    {
      if (client->is_assync)
	send_order(client, list, lo);
      else
      {
	this->orders->put(this->orders, list);
	return ;
      }
      pthread_mutex_lock(&client->ready_mutex);
      clock_gettime(CLOCK_REALTIME, &ts);
      ts.tv_sec += 1;
      pthread_cond_timedwait(&client->ready_writing,
	  &client->ready_mutex, &ts);
      pthread_mutex_unlock(&client->ready_mutex);
    }
  delete_list(list);
  delete_socket(client);
}

static void	*thread_poporder(void *arg)
{
  t_d_arg	*a;
  t_dispatcher	*this;
  t_socket	*client;
  t_list	*l_orders;

  a = (t_d_arg*)arg;
  this = a->server;
  client = a->socket;
  l_orders = a->l_orders;
  client->is_assync = 1;
  st_loop(this, client, l_orders);
  return (NULL);
}

void		*dispatcher_connection(void *arg)
{
  t_s_arg	*a;
  t_d_arg	*da;
  t_dispatcher	*this;
  t_socket	*client;
  t_list	*l_orders;
  pthread_t	th;

  if (!(da = malloc(sizeof(t_d_arg))))
    return (NULL);
  l_orders = new_list();
  a = (t_s_arg*)arg;
  this = a->server;
  client = a->socket;
  da->server = this;
  da->socket = client;
  da->l_orders = l_orders;
  send_data(this, client);
  pthread_create(&th, NULL, &(thread_poporder), da);
  st_nt(this, client, l_orders);
  client->is_assync = 0;
  pthread_cond_broadcast(&this->orders->is_fill);
  pthread_join(th, NULL);
  this->orders->put(this->orders, l_orders);
  delete_list(l_orders);
  return (NULL);
}
