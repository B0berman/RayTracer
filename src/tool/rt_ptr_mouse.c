/*
** rt_ptr_mouse.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_favar_a/MUL_2014_rtracer
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Thu Jun  4 17:33:31 2015 walbec_h
** Last update Sat Jun  6 16:17:13 2015 walbec_h
*/

#include	"rt.h"

int		rt_ptr_mouse(int key, int x, int y, t_rt *rt)
{
  if (key == 1)
    {
      rt_init_loop(rt, &rt->coord, x, y);
      rt_loop(rt);
    }
  return (0);
}
