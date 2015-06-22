/*
** rt_translate.c for tool in /home/zack/Projects/MUL_2014_rtracer/src/tool
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue Apr  7 19:20:03 2015 hugo walbecq
** Last update lun. juin 01 02:05:51 2015 Antoine Favarel
*/

#include	"rt.h"

void		rt_translate(t_coord *coord, t_obj *obj, int i)
{
  if (i == 0)
    {
      coord->xo -= obj->x;
      coord->yo -= obj->y;
      coord->zo -= obj->z;
    }
  else
    {
      coord->xo += obj->x;
      coord->yo += obj->y;
      coord->zo += obj->z;
    }
}
