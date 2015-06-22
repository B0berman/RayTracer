/*
** rt_mkobj.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_favar_a/MUL_2014_rtracer/src
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue May  5 16:08:16 2015 walbec_h
** Last update Sat Jun  6 13:46:47 2015 walbec_h
*/

#include	<stdlib.h>
#include	"rt.h"

t_obj		*rt_mkobj()
{
  t_obj		*obj;

  if ((obj = malloc(sizeof(t_obj))) == NULL)
    exit(EXIT_FAILURE);
  obj->type = T_CYLINDER;
  obj->len = 50;
  obj->color = 0xFF0000;
  obj->reflex = 0.7;
  obj->trans = 0;
  obj->x = -200;
  obj->y = 200;
  obj->z = 100;
  obj->rx = 0;
  obj->ry = 0;
  obj->rz = 0;
  return (obj);
}
