/*
** average.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_rtracer
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Mon Mar 30 13:23:47 2015 hugo walbecq
** Last update Sun Apr 26 13:25:38 2015 walbec_h
*/

#include	"rt.h"

uint		rt_average(uint *color, int nb)
{
  t_union	tmp;
  t_union	res;
  int		r;
  int		g;
  int		b;
  int		i;

  i = 1;
  res.color = color[0];
  r = res.rgb.r;
  g = res.rgb.g;
  b = res.rgb.b;
  while (i < nb)
    {
      tmp.color = color[i++];
      r += tmp.rgb.r;
      g += tmp.rgb.g;
      b += tmp.rgb.b;
    }
  if (nb == 0)
    nb++;
  res.rgb.r = r / nb;
  res.rgb.g = g / nb;
  res.rgb.b = b / nb;
  return (res.color);
}
