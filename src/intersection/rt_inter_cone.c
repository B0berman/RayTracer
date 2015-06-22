/*
** rt_inter_cone.c for intersection in /home/zack/Projects/MUL_2014_rtracer/src/intersection
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue May  5 16:01:43 2015 walbec_h
** Last update lun. juin 01 02:06:53 2015 Antoine Favarel
*/

#include	"rt.h"

t_calc		rt_inter_cone(t_obj *obj, t_coord *coord)
{
  t_calc	calc;

  rt_translate(coord, obj, 0);
  calc.a = (pow(coord->vx, 2) + pow(coord->vy, 2))
    - pow(coord->vz, 2) * TAN(obj->len);
  calc.b = 2 * ((coord->xo * coord->vx + coord->yo * coord->vy)
		- ((coord->zo * coord->vz) * TAN(obj->len)));
  calc.c = (pow(coord->xo, 2) + pow(coord->yo, 2))
    - pow(coord->zo, 2) * TAN(obj->len);
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
