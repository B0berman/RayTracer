/*
** elem_dup.c for list in /home/zack/neptune/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 17:27:37 2015 Antoine Favarel
** Last update dim. mai 31 18:12:56 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"neptune/list.h"

t_elem		*elem_dup(t_elem *this)
{
  t_elem	*elem;

  if (!this)
    return (NULL);
  if (!(elem = _mush(this->mem, this->size_of_mem)))
    return (NULL);
  elem->id = this->id;
  return (elem);
}
