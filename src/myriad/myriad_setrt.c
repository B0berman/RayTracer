/*
** myriad_setrt.c for myriad in /home/zack/Projects/MUL_2014_rtracer/src/myriad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. mai 31 21:10:05 2015 Antoine Favarel
** Last update dim. mai 31 21:15:34 2015 Antoine Favarel
*/

#include	"myriad.h"

t_list		*myriad_setrt(t_rt *rt)
{
  t_list	*list;
  t_elem	*e;

  list = new_list();
  list->push(list, _mush(rt, sizeof(t_rt)));
  rt->objects->rewind(rt->objects);
  while ((e = rt->objects->next(rt->objects)))
    list->push(list, e->dup(e));
  rt->spots->rewind(rt->spots);
  while ((e = rt->spots->next(rt->spots)))
    list->push(list, e->dup(e));
  return (list);
}
