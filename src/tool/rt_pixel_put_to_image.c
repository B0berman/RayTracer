/*
** rt_pixel_put_to_image.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_rtracer/new/src/tool
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Thu Apr  9 13:02:21 2015 walbec_h
** Last update Wed May  6 19:46:04 2015 walbec_h
*/

#include	"rt.h"

int		rt_pixel_put_to_image(t_rt *rt, int x, int y)
{
  int		a;
  int		locate;

  locate = (rt->size_line * y) + (x * rt->bpp / 8);
  a = mlx_get_color_value(rt->mlx_ptr, rt->color);
  rt->data[locate] = a & 255;
  rt->data[locate + 1] = a >> 8 & 255;
  rt->data[locate + 2] = a >> 16 & 255;
  return (0);
}
