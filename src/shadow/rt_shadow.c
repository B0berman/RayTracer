/*
** rt_shadow.c for shadow in /home/meunie_k/rendu/MUL_2014_rtracer/src/shadow
** 
** Made by meunie_k
** Login   <meunie_k@epitech.net>
** 
** Started on  Fri Apr 10 14:00:53 2015 Antoine Meuniez
** Last update Sun Jun  7 23:00:01 2015 Antoine Meuniez
*/

#include	"neptune/list.h"
#include	"rt.h"

void		rt_shadow(t_rt *rt, t_coord *inter, t_color *rgb)
{
  t_elem	*elem;
  t_calc	calc;
  t_obj		*obj;
  double	k;
  double	n_k;

  k = 10000;
  rt->objects->rewind(rt->objects);
  while ((elem = rt->objects->next(rt->objects)))
    if ((obj = elem->mem) && obj != rt->obj)
      {
	rt_rotate(inter, obj, 0);
	calc = rt_check_obj(inter, obj);
	rt_rotate(inter, obj, 1);
	n_k = rt_delta_shadow(calc);
	k = (n_k < k && n_k != 0) ? n_k : k;
      }
  if (k > 0.00001 && k < 1)
    {
      rgb->r *= k;
      rgb->g *= k;
      rgb->b *= k;
    }
}
