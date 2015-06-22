/*
** rt_inter_plan.c for intersection in /home/zack/Projects/MUL_2014_rtracer/src/intersection
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue May  5 16:01:56 2015 walbec_h
** Last update lun. juin 01 02:07:28 2015 Antoine Favarel
*/

#include       "rt.h"

t_calc		rt_inter_plan(t_obj *obj, t_coord *coord)
{
  t_calc	calc;

  calc.k2 = 10000;
  rt_translate(coord, obj, 0);
  if (coord->vz != 0)
    calc.k2 = -(coord->zo / coord->vz);
  calc.k1 = calc.k2;
  rt_translate(coord, obj, 1);
  return (calc);
}
