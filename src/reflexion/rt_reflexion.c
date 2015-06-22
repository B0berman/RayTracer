/*
** rt_reflexion.c for  in /home/skanx/MUL_2014_rtracer/src/reflexion
**
** Made by Michalski Lucas
** Login   <michal_l@epitech.net>
**
** Started on  Tue Jun  2 09:31:20 2015 Michalski Lucas
** Last update Sun Jun  7 23:19:19 2015 Michalski Lucas
*/

#include	"rt.h"

static void	rt_mk_reflex(uint color, t_rt *rt, double r_obj)
{
  t_union	uni;
  t_union	reflex;
  uchar		r;
  uchar		g;
  uchar		b;

  uni.color = color;
  reflex.color = rt->color;
  r = reflex.rgb.r * r_obj + uni.rgb.r * (1 - r_obj);
  g = reflex.rgb.g * r_obj + uni.rgb.g * (1 - r_obj);
  b = reflex.rgb.b * r_obj + uni.rgb.b * (1 - r_obj);
  uni.rgb.r = r;
  uni.rgb.g = g;
  uni.rgb.b = b;
  rt->color = uni.color;
}

void		rt_reflex(t_rt *rt, uint color, t_coord *inter, double reflex)
{
  double	scalaire;
  double	*n;

  n = rt_getnorme(rt->obj, inter);
  scalaire = sqrt(X2(n[0]) + X2(n[1]) + X2(n[2]));
  n[0] /= scalaire;
  n[1] /= scalaire;
  n[2] /= scalaire;
  scalaire = (n[0] * rt->coord.vx + n[1] * rt->coord.vy
	      + n[2] * rt->coord.vz);
  inter->vx = (-2 * n[0] * scalaire) + rt->coord.vx;
  inter->vy = (-2 * n[1] * scalaire) + rt->coord.vy;
  inter->vz = (-2 * n[2] * scalaire) + rt->coord.vz;
  inter->k = 10000;
  rt_rotate_eyes(inter, rt->obj);
  rt->coord = *inter;
  rt_loop(rt);
  if (rt->coord.xo > rt->inter.xo)
    {
      rt->color = color;
      return ;
    }
  rt_mk_reflex(color, rt, reflex);
}
