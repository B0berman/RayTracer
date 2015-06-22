/*
** rt_light.c for rt in /home/Moon/rendu/MUL_2014_rtracer/src/light
** 
** Made by Pierre de Berny
** Login   <Moon@epitech.net>
** 
** Started on  Tue May  5 15:20:37 2015 Pierre de Berny
** Last update Sun Jun  7 20:16:54 2015 Pierre de Berny
*/

#include	<math.h>
#include	"neptune/list.h"
#include	"rt.h"

static uint	rt_make_light(t_rt *rt, double cosa, t_spot *spot)
{
  t_union	uni;
  int		color;
  uchar		r;
  uchar		g;
  uchar		b;

  color = rt->color * (1 - spot->brill) + spot->color * spot->brill;
  uni.color = color;
  r = uni.rgb.r;
  g = uni.rgb.g;
  b = uni.rgb.b;
  uni.rgb.r *= cosa;
  uni.rgb.g *= cosa;
  uni.rgb.b *= cosa;
  if (cosa < 0.000001)
    uni.color = 0x000000;
  if (uni.rgb.r < (r * AMBIANCE))
    uni.rgb.r = (r * AMBIANCE);
  if (uni.rgb.g < (g * AMBIANCE))
    uni.rgb.g = (g * AMBIANCE);
  if (uni.rgb.b < (b * AMBIANCE))
    uni.rgb.b = (b * AMBIANCE);
  return (uni.color);
}

uint		rt_light(t_rt *rt, t_spot *spot, double *n)
{
  double	cosa;
  double	scalair;

  scalair = sqrt(pow(n[0], 2) + pow(n[1], 2) + pow(n[2], 2));
  n[0] /= scalair;
  n[1] /= scalair;
  n[2] /= scalair;
  scalair = sqrt(pow(rt->inter.vx, 2) + pow(rt->inter.vy, 2)
    + pow(rt->inter.vz, 2));
  rt->inter.vx /= scalair;
  rt->inter.vy /= scalair;
  rt->inter.vz /= scalair;
  cosa = (rt->inter.vx * n[0] + rt->inter.vy * n[1] + rt->inter.vz * n[2]);
  return (rt_make_light(rt, cosa, spot));
}
