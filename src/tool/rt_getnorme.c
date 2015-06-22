/*
** rt_getnorme.c for tool in /Bureau/MUL_2014_rtracer
** 
** Made by wachow_a
** Login   <wachow_a@epitech.net>
** 
** Started on  Sat Apr 25 16:52:10 2015 wachow_a
** Last update Sun Jun  7 23:40:59 2015 Wako
*/

#include	<stdlib.h>
#include	"rt.h"

double		*rt_getnorme(t_obj *obj, t_coord *inter)
{
  double	*n;

  if ((n = malloc(sizeof(double) * 3)) == NULL)
    rt_exit("mallocation error (rt_getnorme.c)\n");
  rt_rotate(inter, obj, 0);
  if (obj->type == T_PLAN)
    {
      n[0] = 0;
      n[1] = 0;
      n[2] = 1000;
    }
  else
    {
      n[0] = inter->xo - obj->x;
      n[1] = inter->yo - obj->y;
      if (obj->type == T_SPHERE)
	n[2] = inter->zo - obj->z;
      else
	n[2] = 0;
    }
  rt_rotate(inter, obj, 1);
  return (n);
}
