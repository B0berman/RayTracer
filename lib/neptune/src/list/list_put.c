/*
** list_put.c for list in /home/zack/neptune/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 25 14:15:38 2015 Antoine Favarel
** Last update ven. mai 29 18:39:16 2015 Antoine Favarel
*/

#include	"neptune/list.h"

void		list_put(t_list *this, t_list *src)
{
  t_elem	*elem;

  if (this && src)
  {
    src->lock(src);
    src->rewind(src);
    while ((elem = src->next(src)))
      this->push(this, elem->dup(elem));
    src->unlock(src);
  }
}
