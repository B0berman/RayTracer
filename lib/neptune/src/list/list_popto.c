/*
** list_popto.c for list in /home/zack/neptune/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. mai 29 15:46:51 2015 Antoine Favarel
** Last update ven. mai 29 15:58:20 2015 Antoine Favarel
*/

#include	"neptune/list.h"

t_list		*list_popto(t_list *this, size_t nb)
{
  t_list	*list;
  int		i;
  int		max;

  i = -1;
  if (!this)
    return (NULL);
  list = new_list();
  this->lock(this);
  while (this->length == 0)
    pthread_cond_wait(&this->is_fill, &this->mutex);
  max = (nb > this->length) ? this->length : nb;
  while (++i < max)
    list->push(list, this->pop(this));
  this->unlock(this);
  return (list);
}
