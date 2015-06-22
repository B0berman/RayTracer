/*
** st_nt.c for dispatcher in /home/zack/neptune/src/clust/dispatcher
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. mai 29 16:17:08 2015 Antoine Favarel
** Last update mer. juin 03 16:53:00 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"neptune/clust/dispatcher.h"

static void	st_elem(t_dispatcher *this, t_socket *client, t_list *lo)
{
  t_elem	*respond;
  t_elem	*akn;

  respond = new_elem();
  akn = _wrap(new_metadata(MR_AKN, MD_DATA), sizeof(t_metadata));
  if (respond->load(respond, (t_io*)client) == EXIT_FAILURE)
    return ;
  this->responds->push(this->responds, respond->dup(respond));
  lo->remove(lo, lo->get(lo, respond->id));
  akn->save(akn, (t_io*)client);
  delete_elem(akn);
  delete_elem(respond);
}

static void	st_loop(t_dispatcher *this, t_socket *c, t_list *lo, t_list *r)
{
  t_elem	*tmp;

  r->rewind(r);
  while ((tmp = r->next(r)))
  {
    c->lock(c);
    c->counter--;
    c->unlock(c);
    if (tmp->check(tmp) == tmp->magic_cmp)
    {
      lo->remove(lo, lo->get(lo, tmp->id));
      this->responds->push(this->responds, tmp->dup(tmp));
    }
    else
      this->orders->push(this->orders, lo->get(lo, tmp->id));
    if (c->counter == 0)
      pthread_cond_signal(&c->ready_writing);
  }
}

static void	st_list(t_dispatcher *this, t_socket *c, t_list *lo)
{
  t_list	*respond;
  t_elem	*akn;

  respond = new_list();
  akn = _wrap(new_metadata(MR_AKN, MD_DATA), sizeof(t_metadata));
  if (respond->load(respond, (t_io*)c) == EXIT_FAILURE)
    return ;
  st_loop(this, c, lo, respond);
  akn->save(akn, (t_io*)c);
  delete_elem(akn);
  delete_list(respond);
}

void		st_nt(t_dispatcher *this, t_socket *client, t_list *lo)
{
  t_metadata	*meta;
  t_elem	*respond;

  respond = new_elem();
  while (respond->load(respond, (t_io*)client) == EXIT_SUCCESS)
  {
    client->lock(client);
    if ((meta = (t_metadata*)respond->mem)->role == MR_RESPONS
	&& meta->desc == MD_DATA)
      st_elem(this, client, lo);
    else if (meta->role == MR_RESPONS && meta->desc == MD_LIST)
      st_list(this, client, lo);
    client->unlock(client);
  }
}
