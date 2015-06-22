/*
** rt_mkspot.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_favar_a
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Thu Jun 11 12:49:11 2015 walbec_h
** Last update Thu Jun 11 13:37:04 2015 walbec_h
*/

#include	<stdlib.h>
#include	"rt.h"

t_spot		*rt_mkspot(uint color, double brill, double pow)
{
  t_spot	*spot;

  if ((spot = malloc(sizeof(t_obj))) == NULL)
    exit(EXIT_FAILURE);
  spot->color = color;
  spot->brill = brill;
  spot->power = pow;
  spot->spot.xo = -1650;
  spot->spot.yo = -400;
  spot->spot.zo = 600;
  return (spot);
}

t_spot		*rt_mkspot_b(uint color, double brill, double pow)
{
  t_spot	*spot;

  if ((spot = malloc(sizeof(t_obj))) == NULL)
    exit(EXIT_FAILURE);
  spot->color = color;
  spot->brill = brill;
  spot->power = pow;
  spot->spot.xo = -650;
  spot->spot.yo = 400;
  spot->spot.zo = 300;
  return (spot);
}

t_spot		*rt_mkspot_c(uint color, double brill, double pow)
{
  t_spot	*spot;

  if ((spot = malloc(sizeof(t_obj))) == NULL)
    exit(EXIT_FAILURE);
  spot->color = color;
  spot->brill = brill;
  spot->power = pow;
  spot->spot.xo = -50;
  spot->spot.yo = 0;
  spot->spot.zo = 700;
  return (spot);
}

void		create_spots(t_rt *rt)
{
  t_spot	*spot;

  rt->spots = new_list();
  spot = rt_mkspot(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_b(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_b(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_b(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_b(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_b(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_b(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_b(0xFFFFFF, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot_c(0x000000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
}
