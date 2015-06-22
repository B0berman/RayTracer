/*
** monad_main.c for monad in /home/zack/neptune/src/monad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 18:01:10 2015 Antoine Favarel
** Last update lun. juin 01 15:35:10 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"neptune/monad.h"

void		*monad_main(void *wrapper)
{
  t_monad	*this;
  t_elem	*tmp;
  t_data	*data;
  t_elem	*n_elem;

  this = (t_monad*)wrapper;
  if (!this->queue_in)
    return (NULL);
  while (42)
    while ((tmp = this->queue_in->pop(this->queue_in)))
      if (this->gst_actor)
      {
	data = this->gst_actor(this, (t_data *)tmp);
	n_elem = _wrap(data->mem, data->size_of_mem);
	n_elem->id = data->id;
	free(data);
	this->queue_out->push(this->queue_out, n_elem);
      }
  return (NULL);
}

