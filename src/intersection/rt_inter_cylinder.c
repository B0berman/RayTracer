/*
** rt_inter_cylinder.c for intersection in /home/zack/Projects/MUL_2014_rtracer/src/intersection
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue May  5 16:02:17 2015 walbec_h
** Last update lun. juin 01 02:07:11 2015 Antoine Favarel
*/

#include	<math.h>
#include	"rt.h"

t_calc		rt_inter_cylinder(t_obj *obj, t_coord *coord)
{
  t_calc	calc;

  rt_translate(coord, obj, 0);
  calc.a = pow(coord->vx, 2) + pow(coord->vy, 2);
  calc.b = 2 * (coord->xo * coord->vx + coord->yo * coord->vy);
  calc.c = pow(coord->xo, 2) + pow(coord->yo, 2) - pow(obj->len, 2);
  calc.d = pow(calc.b, 2) - (4 * calc.a * calc.c);
  rt_translate(coord, obj, 1);
  calc.k1 = 10000;
  calc.k2 = 10000;
  if (calc.d >= 0)
    {
      calc.k1 = (-calc.b - sqrt(calc.d)) / (2 * calc.a);
      calc.k2 = (-calc.b + sqrt(calc.d)) / (2 * calc.a);
    }
  return (calc);
}
