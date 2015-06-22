/*
** rt_checkobj.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_favar_a/MUL_2014_rtracer
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Sat Apr 25 17:30:08 2015 walbec_h
** Last update Thu May  7 11:21:52 2015 walbec_h
*/

#include	"rt.h"

t_calc		rt_check_obj(t_coord *coord, t_obj *obj)
{
  t_calc	calc;

  if (obj->type == T_SPHERE)
    calc = rt_inter_sphere(obj, coord);
  else if (obj->type == T_PLAN)
    calc = rt_inter_plan(obj, coord);
  else if (obj->type == T_CONE)
    calc = rt_inter_cone(obj, coord);
  else if (obj->type == T_CYLINDER)
    calc = rt_inter_cylinder(obj, coord);
  return (calc);
}
