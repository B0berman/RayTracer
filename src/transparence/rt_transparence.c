/*
** transparence.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_favar_a/MUL_2014_rtracer/src/transparence
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Thu May 28 14:10:11 2015 walbec_h
** Last update Sun Jun  7 15:44:19 2015 Pierre de Berny
*/

#include	"rt.h"

void		put_trans(t_rt *rt, double coef, t_union *uni, t_union *trans)
{
  int		r;
  int		g;
  int		b;

  r = trans->rgb.r * coef + uni->rgb.r * (1 - coef);
  g = trans->rgb.g * coef + uni->rgb.g * (1 - coef);
  b = trans->rgb.b * coef + uni->rgb.b * (1 - coef);
  uni->rgb.r = r;
  uni->rgb.g = g;
  uni->rgb.b = b;
  rt->color = uni->color;
}

void		rt_trans(t_rt *rt, uint color, t_coord *inter)
{
  double	coef;
  t_union	uni;
  t_union	trans;

  if (rt->coord.k == 10000)
    return ;
  rt->coord.xo = inter->xo;
  rt->coord.yo = inter->yo;
  rt->coord.zo = inter->zo;
  coef = rt->obj->trans;
  rt_loop(rt);
  if (rt->coord.k == 10000)
    rt->color = 0x000000;
  uni.color = color;
  trans.color = rt->color;
  put_trans(rt, coef, &uni, &trans);
}
