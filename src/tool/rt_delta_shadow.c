/*
** rt_delta_shadow.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_rtracer/src
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue Apr  7 19:26:56 2015 hugo walbecq
** Last update Fri May 29 15:21:23 2015 walbec_h
*/

#include	"rt.h"

double		rt_delta_shadow(t_calc calc)
{
  if (calc.k1 < calc.k2 && calc.k1 > 0.00001)
    return (calc.k1);
  else if (calc.k2 < calc.k1 && calc.k2 > 0.00001)
    return (calc.k2);
  return (0);
}
