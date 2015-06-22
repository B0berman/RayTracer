/*
** rt_test.c for src in /home/zack/Projects/MUL_2014_rtracer/src
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue May  5 15:45:01 2015 walbec_h
** Last update dim. juin 07 22:28:09 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"neptune/list.h"
#include	"rt.h"

t_obj		*mkobj()
{
  t_obj		*obj;

  if ((obj = malloc(sizeof(t_obj))) == NULL)
    exit(1);
  obj->type = T_PLAN;
  obj->len = 50;
  obj->color = 0x00FF00;
  obj->reflex = 0;
  obj->trans = 0;
  obj->x = 0;
  obj->y = 0;
  obj->z = -100;
  obj->rx = 0;
  obj->ry = 0;
  obj->rz = 0;
  return (obj);
}

t_obj		*mkobj_bis()
{
  t_obj		*obj;

  if ((obj = malloc(sizeof(t_obj))) == NULL)
    exit(1);
  obj->type = T_SPHERE;
  obj->len = 50;
  obj->color = 0x0000FF;
  obj->reflex = 0;
  obj->trans = 0.6;
  obj->x = -500;
  obj->y = -100;
  obj->z = 20;
  obj->rx = 0;
  obj->ry = 0;
  obj->rz = 0;
  return (obj);
}

t_obj		*mkobj_bi()
{
  t_obj		*obj;

  if ((obj = malloc(sizeof(t_obj))) == NULL)
    exit(1);
  obj->type = T_SPHERE;
  obj->len = 50;
  obj->color = 0xFF0000;
  obj->reflex = 0;
  obj->trans = 0;
  obj->x = -100;
  obj->y = -300;
  obj->z = -250;
  obj->rx = 0;
  obj->ry = 0;
  obj->rz = 0;
  return (obj);
}

void		rt_init_test(t_rt *rt)
{
  t_obj		*obj;
  t_spot	*spot;

  rt->spots = new_list();
  rt->objects = new_list();
  obj = rt_mkobj();
  spot = rt_mkspot(0x0000FF, 0, 0);
  rt->objects->push(rt->objects, _wrap(obj, sizeof(t_obj)));
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  obj = mkobj();
  rt->objects->push(rt->objects, _wrap(obj, sizeof(t_obj)));
  obj = mkobj_bis();
  rt->objects->push(rt->objects, _wrap(obj, sizeof(t_obj)));
  obj = mkobj_bi();
  rt->objects->push(rt->objects, _wrap(obj, sizeof(t_obj)));
  spot = rt_mkspot(0xFF0000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
  spot = rt_mkspot(0xFF0000, 0, 0);
  rt->spots->push(rt->spots, _wrap(spot, sizeof(t_spot)));
}
