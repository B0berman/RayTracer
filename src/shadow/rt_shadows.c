/*
** rt_shadow.c for  in /home/meunie_k/rendu/MUL_2014_rtracer/src/shadow
** 
** Made by meunie_k
** Login   <meunie_k@epitech.net>
** 
** Started on  Fri Apr 10 13:52:23 2015 Antoine Meuniez
** Last update Sun Jun  7 22:58:33 2015 Antoine Meuniez
*/

#include	<stdlib.h>
#include	"neptune/list.h"
#include	"rt.h"

static void	malloc_check(uint *ptr)
{
  if (ptr == NULL)
    exit(EXIT_FAILURE);
}

void		rt_shadows(t_rt *rt, t_list *spots)
{
  uint		*colors;
  int		x;
  uint		tmp_color;
  t_union	uni;
  t_elem	*elem;
  t_spot	*spot;

  x = 0;
  malloc_check((colors = malloc(sizeof(int) * (spots->length + 1))));
  spots->rewind(spots);
  tmp_color = rt->color;
  while ((elem = spots->next(spots)))
    if ((spot = elem->mem))
      {
	uni.color = tmp_color;
	rt->inter.vx = spot->spot.xo - rt->inter.xo;
	rt->inter.vy = spot->spot.yo - rt->inter.yo;
	rt->inter.vz = spot->spot.zo - rt->inter.zo;
	rt_shadow(rt, &rt->inter, &uni.rgb);
	colors[x++] = uni.color;
      }
  rt->color = uni.color;
  if (x > 1)
    rt->color = rt_average(colors, spots->length);
  free(colors);
}
