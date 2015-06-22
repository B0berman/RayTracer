/*
** rt_lights.c for rt in /home/Moon/rendu/MUL_2014_rtracer/src/light
** 
** Made by Pierre de Berny
** Login   <Moon@epitech.net>
** 
** Started on  Tue May  5 15:22:40 2015 Pierre de Berny
** Last update Sun Jun  7 20:16:45 2015 Pierre de Berny
*/

#include	<stdlib.h>
#include	"neptune/list.h"
#include	"rt.h"

void		rt_lights(t_rt *rt, t_list *spots)
{
  uint		*colors;
  int		x;
  t_spot	*spot;
  t_elem	*elem;
  double	*n;

  n = rt_getnorme(rt->obj, &rt->inter);
  x = 0;
  if (rt->obj->type == T_CONE || rt->obj->type == T_CYLINDER)
    n[2] = 0;
  if ((colors = malloc(sizeof(int) * (spots->length + 1))) == NULL)
    exit(EXIT_FAILURE);
  spots->rewind(spots);
  while ((elem = spots->next(spots)))
    if ((spot = elem->mem))
      {
	rt->inter.vx = spot->spot.xo - rt->inter.xo;
	rt->inter.vy = spot->spot.yo - rt->inter.yo;
	rt->inter.vz = spot->spot.zo - rt->inter.zo;
	colors[x++] = rt_light(rt, spot, n);
      }
  rt->color = rt_average(colors, spots->length);
  free(n);
  free(colors);
}
