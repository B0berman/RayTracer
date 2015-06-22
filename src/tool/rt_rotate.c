/*
** rt_rotate.c for tool in /home/zack/Projects/MUL_2014_rtracer/src/tool
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Apr 10 14:18:01 2015 walbec_h
** Last update lun. juin 01 01:58:31 2015 Antoine Favarel
*/

#include	"rt.h"

static void	rotate_x(double *y, double *z, int a)
{
  double	z1;
  double	y1;
  double	cosa;
  double	sina;

  cosa = cos(RAD(a));
  sina = sin(RAD(a));
  y1 = *y;
  z1 = *z;
  *y = cosa * y1 - sina * z1;
  *z = sina * y1 + cosa * z1;
}

static void	rotate_y(double *x, double *z, int a)
{
  double	z1;
  double	x1;
  double	cosa;
  double	sina;

  cosa = cos(RAD(a));
  sina = sin(RAD(a));
  x1 = *x;
  z1 = *z;
  *x = cosa * x1 + sina * z1;
  *z = -sina * x1 + cosa * z1;
}

static void	rotate_z(double *x, double *y, int a)
{
  double	x1;
  double	y1;
  double	cosa;
  double	sina;

  cosa = cos(RAD(a));
  sina = sin(RAD(a));
  y1 = *y;
  x1 = *x;
  *x = cosa * x1 - sina * y1;
  *y = sina * x1 + cosa * y1;
}

void		rt_rotate(t_coord *coord, t_obj *obj, int i)
{
  if (i == 0)
    {
      rotate_x(&coord->vy, &coord->vz, -obj->rx);
      rotate_y(&coord->vx, &coord->vz, -obj->ry);
      rotate_z(&coord->vx, &coord->vy, -obj->rz);
      rotate_x(&coord->yo, &coord->zo, -obj->rx);
      rotate_y(&coord->xo, &coord->zo, -obj->ry);
      rotate_z(&coord->xo, &coord->yo, -obj->rz);
    }
  else
    {
      rotate_x(&coord->vy, &coord->vz, obj->rx);
      rotate_y(&coord->vx, &coord->vz, obj->ry);
      rotate_z(&coord->vx, &coord->vy, obj->rz);
      rotate_x(&coord->yo, &coord->zo, obj->rx);
      rotate_y(&coord->xo, &coord->zo, obj->ry);
      rotate_z(&coord->xo, &coord->yo, obj->rz);
    }
}

void		rt_rotate_eyes(t_coord *coord, t_obj *obj)
{
  rotate_x(&coord->vy, &coord->vz, obj->rx);
  rotate_y(&coord->vx, &coord->vz, obj->ry);
  rotate_z(&coord->vx, &coord->vy, obj->rz);
}
