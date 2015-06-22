/*
** myriad_getrt.c for myriad in /home/zack/Projects/MUL_2014_rtracer/src/myriad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. mai 31 21:03:00 2015 Antoine Favarel
** Last update dim. mai 31 21:08:23 2015 Antoine Favarel
*/

#include	"myriad.h"

t_rt		*myriad_getrt(t_monad *this)
{
  t_rt		*rt;
  t_elem	*e;

  this->data->lock(this->data);
  e = _mush(this->data->first->mem, sizeof(t_rt));
  rt = e->mem;
  rt->objects = new_list();
  rt->spots = new_list();
  e = this->data->first->next;
  while (e)
  {
    if (e->size_of_mem == sizeof(t_obj))
      rt->objects->push(rt->objects, e->dup(e));
    else if  (e->size_of_mem == sizeof(t_spot))
      rt->spots->push(rt->spots, e->dup(e));
    e = e->next;
  }
  this->data->unlock(this->data);
  return (rt);
}
