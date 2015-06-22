/*
** rt_ptr_key.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_favar_a/MUL_2014_rtracer
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Thu Jun  4 17:33:08 2015 walbec_h
** Last update Sat Jun  6 16:25:36 2015 walbec_h
*/

#include	<stdlib.h>
#include	"rt.h"

static void	move_x(int key, t_rt *rt)
{
  if (key == 65365 && rt->obj != NULL)
    {
      rt->obj->x += 30;
      rt_image_loop(rt);
    }
  else if (key == 65366 && rt->obj != NULL)
    {
      rt->obj->x -= 30;
      rt_image_loop(rt);
    }
}

int		rt_ptr_key(int key, t_rt *rt)
{
  if (key == 65307)
    rt_exit("exit\n");
  else if (key == 65363 && rt->obj != NULL)
    {
      rt->obj->y -= 30;
      rt_image_loop(rt);
    }
  else if (key == 65361 && rt->obj != NULL)
    {
      rt->obj->y += 30;
      rt_image_loop(rt);
    }
  else if (key == 65362 && rt->obj != NULL)
    {
      rt->obj->z += 30;
      rt_image_loop(rt);
    }
  else if (key == 65364 && rt->obj != NULL)
    {
      rt->obj->z -= 30;
      rt_image_loop(rt);
    }
  else if (key == 65365 || key == 65366)
    move_x(key, rt);
  return (0);
}
