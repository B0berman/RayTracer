/*
** rt_delta.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_rtracer/new/src
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue Apr  7 19:05:26 2015 hugo walbecq
** Last update Thu May 28 13:56:51 2015 walbec_h
*/

#include	"rt.h"

double		rt_delta(t_rt *rt, t_calc calc, t_obj *obj)
{
  if (obj->type == T_PLAN)
    if (calc.k2 > 0.000001 && calc.k2 < rt->coord.k)
      {
	rt->color = obj->color;
	rt->obj = obj;
	return (calc.k2);
      }
  if ((calc.k1 < calc.k2 && calc.k1 > 0.0001 && calc.k1 < rt->coord.k) ||
      (calc.k1 > calc.k2 && calc.k2 < 0.0001 && calc.k1 < rt->coord.k))
    {
      rt->obj = obj;
      rt->color = obj->color;
      return (calc.k1);
    }
  else if ((calc.k2 < calc.k1 && calc.k2 > 0.0001 && calc.k2 < rt->coord.k) ||
	   (calc.k2 > calc.k1 && calc.k1 < 0.0001 && calc.k2 < rt->coord.k))
    {
      rt->obj = obj;
      rt->color = obj->color;
      return (calc.k2);
    }
  return (10000);
}
