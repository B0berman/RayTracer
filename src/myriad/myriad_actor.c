/*
** myriad_actor.c for myriad in /home/zack/Projects/MUL_2014_rtracer/src/myriad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. mai 31 20:53:16 2015 Antoine Favarel
** Last update dim. juin 07 15:45:29 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"myriad.h"

static void	st_act(t_rt *rt, t_pixel *pixel, int i)
{
  double	x;
  double	y;

  x = pixel->x[i];
  y = pixel->y[i];
  if (x == -1 && y == -1)
    return ;
  rt_init_loop(rt, &rt->coord, x, y);
  if (x > 0 && y > 0 && x < rt->size_x && y < rt->size_y
      && rt->aliasing > 0)
    rt_aliasing(rt, x, y);
  else
    rt_loop(rt);
  pixel->color[i] = rt->color;
}

t_data		*myriad_actor(t_monad *this, t_data *data)
{
  t_rt		*rt;
  t_pixel	*pixel;
  int		i;

  i = -1;
  pixel = (t_pixel*)data->mem;
  rt = myriad_getrt(this);
  while (++i < 3)
    st_act(rt, pixel, i);
  delete_list(rt->objects);
  delete_list(rt->spots);
  free(rt);
  return (data);
}
