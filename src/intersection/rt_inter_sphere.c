/*
** rt_inter_sphere.c for rt in /home/skanx/rendu/MUL_2014_rtracer/src
**
** Made by Michalski Lucas
** Login   <michal_l@epitech.net>
**
** Started on  Tue May  5 16:01:35 2015 Michalski Lucas
** Last update Sun Jun  7 23:16:52 2015 Michalski Lucas
*/

#include	<math.h>
#include	"rt.h"

t_calc		rt_inter_sphere(t_obj *obj, t_coord *coord)
{
  t_calc	calc;

  rt_translate(coord, obj, 0);
  calc.a = coord->vx * coord->vx + coord->vy *
    coord->vy + coord->vz * coord->vz;
  calc.b = 2 * ((coord->xo * coord->vx) + (coord->yo * coord->vy)
		+ (coord->zo * coord->vz));
  calc.c = (coord->xo * coord->xo + coord->yo * coord->yo + coord->zo
	    * coord->zo - obj->len * obj->len);
  calc.d = calc.b * calc.b - (4 * calc.a * calc.c);
  rt_translate(coord, obj, 1);
  if (calc.d >= 0)
    {
      calc.k1 = (-calc.b + sqrt(calc.d)) / (2 * calc.a);
      calc.k2 = (-calc.b - sqrt(calc.d)) / (2 * calc.a);
    }
  else
    {
      calc.k1 = 10000;
      calc.k2 = 10000;
    }
  return (calc);
}
