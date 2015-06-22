/*
** rt_ptr_expose.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_rtracer/new/src/tool
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Apr  3 13:43:54 2015 hugo walbecq
** Last update Mon Apr 20 14:37:13 2015 walbec_h
*/

#include	"rt.h"

int		rt_ptr_expose(t_rt *rt)
{
  mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr,
			  rt->img_ptr, 0, 0);
  return (0);
}
