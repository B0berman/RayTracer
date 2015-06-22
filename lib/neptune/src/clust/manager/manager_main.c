/*
** manager_main.c for manager in /home/zack/neptune/src/clust/manager
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 10:57:04 2015 Antoine Favarel
** Last update mer. juin 03 17:08:23 2015 Antoine Favarel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<limits.h>
#include	<unistd.h>
#include	"neptune/clust/manager.h"

static void	st_update(t_manager *this, t_metadata *meta)
{
  t_elem	*n_d;
  t_list	*n_l;

  if (meta->desc == MD_DATA)
  {
    n_d = new_elem();
    if (n_d->load(n_d, (t_io*)this) == EXIT_SUCCESS)
      this->data->push(this->data, n_d);
  }
  else if (meta->desc == MD_LIST)
  {
    n_l = new_list();
    if (n_l->load(n_l, (t_io*)this) == EXIT_SUCCESS)
      this->update(this, n_l);
  }
}

static void	st_order(t_manager *this, t_metadata *meta)
{
  t_elem	*n_d;
  t_list	*n_l;

  if (meta->desc == MD_DATA)
  {
    n_d = new_elem();
    if (n_d->load(n_d, (t_io*)this) == EXIT_SUCCESS)
      this->in->push(this->in, n_d);
  }
  else if (meta->desc == MD_LIST)
  {
    n_l = new_list();
    n_l->load(n_l, (t_io*)this);
    this->in->put(this->in, n_l);
  }
}

static void	st_network(t_manager *this)
{
  t_data	*data;
  t_metadata	*metadata;

  data = new_data();
  while ((data->load(data, (t_io*)this)) != EXIT_FAILURE)
  {
    metadata = (t_metadata *)data->mem;
    if (metadata->role == MR_DATA)
      st_update(this, metadata);
    else if (metadata->role == MR_ORDER)
      st_order(this, metadata);
    else if (metadata->role == MR_AKN)
      pthread_cond_signal(&this->is_akn);
  }
  free(data);
}

static void	*st_poprespond(void *wrapper)
{
  t_manager	*this;
  t_list	*list;
  t_elem	*send;
  t_metadata	*meta;
  t_timespec	ts;

  this = (t_manager*)wrapper;
  meta = new_metadata(MR_RESPONS, MD_LIST);
  while ((list = this->out->popto(this->out, 1500)))
  {
    send = _wrap(meta, sizeof(t_metadata));
    this->lock(this);
    send->save(send, (t_io*)this);
    list->save(list, (t_io*)this);
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += 1;
    pthread_cond_timedwait(&this->is_akn, &this->mutex, &ts);
    this->unlock(this);
    delete_list(list);
    usleep(300);
  }
  free(meta);
  return (NULL);
}

void		*manager_main(void *wrapper)
{
  t_manager	*this;
  t_monad	*monad;
  int		clust;
  int		i;
  pthread_t	poprespond;

  this = (t_manager*)wrapper;
  clust = sysconf(_SC_NPROCESSORS_ONLN) * this->coexiam;
  i = -1;
  while (++i < clust)
  {
    monad = new_monad(this->in, this->out);
    monad->data = this->data;
    monad->gst_actor = this->actor;
    this->monads->push(this->monads, _wrap(monad, sizeof(t_monad)));
    monad->start(monad);
  }
  pthread_create(&poprespond, NULL, &(st_poprespond), wrapper);
  st_network(this);
  pthread_cancel(poprespond);
  return (NULL);
}
