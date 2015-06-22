/*
** rt_loop.c for tool in /home/zack/Projects/MUL_2014_rtracer/src/tool
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. févr. 22 02:07:19 2015 Antoine Favarel
** Last update dim. juin 07 16:02:45 2015 Antoine Favarel
*/

#include	<unistd.h>
#include	<math.h>
#include	"neptune/list.h"
#include	"neptune/strmut.h"
#include	"myriad.h"
#include	"rt.h"

void		rt_loop(t_rt *rt)
{
  t_elem	*elem;
  t_obj		*obj;
  t_calc	calc;
  double	k;
  double	n_k;

  k = 10000;
  rt->coord.k = k;
  rt->objects->rewind(rt->objects);
  while ((elem = rt->objects->next(rt->objects)))
    if ((obj = elem->mem))
      {
	rt_rotate(&rt->coord, obj, 0);
	calc = rt_check_obj(&rt->coord, obj);
	rt_rotate(&rt->coord, obj, 1);
	k = (n_k = rt_delta(rt, calc, obj)) < k ? n_k : k;
	rt->coord.k = k;
      }
  if (k == 10000)
    return ;
  rt->inter.xo = rt->coord.xo + k * rt->coord.vx;
  rt->inter.yo = rt->coord.yo + k * rt->coord.vy;
  rt->inter.zo = rt->coord.zo + k * rt->coord.vz;
  rt_lights(rt, rt->spots);
  rt_shadows(rt, rt->spots);
}

void		rt_init_loop(t_rt *rt, t_coord *coord, double x, double y)
{
  double	z1;
  double	y1;

  rt->color = 0x000000;
  rt->obj = NULL;
  coord->xo = -1000;
  coord->yo = 0;
  coord->zo = 0;
  y1 = (rt->size_x / 2) - x;
  z1 = (rt->size_y / 2) - y;
  coord->vx = (rt->size_x / 2) / tan(30.0 * M_PI / 180);
  coord->vy = y1 - coord->yo;
  coord->vz = z1 - coord->zo;
}

void		rt_reflex_trans(t_rt *rt)
{
  if (rt->obj != NULL && rt->obj->trans > 0.0001)
    rt_trans(rt, rt->color, &rt->inter);
  if (rt->obj != NULL && rt->obj->reflex > 0.0001)
    rt_reflex(rt, rt->color, &rt->inter, rt->obj->reflex);
}

t_rt		*getrt(t_list *list)
{
  t_rt		*rt;
  t_elem	*e;

  list->lock(list);
  e = _mush(list->first->mem, sizeof(t_rt));
  rt = e->mem;
  rt->objects = new_list();
  rt->spots = new_list();
  e = list->first->next;
  while (e)
  {
    if (e->size_of_mem == sizeof(t_obj))
      rt->objects->push(rt->objects, e->dup(e));
    else if (e->size_of_mem == sizeof(t_spot))
      rt->spots->push(rt->spots, e->dup(e));
    e = e->next;
  }
  list->unlock(list);
  return (rt);
}

void		rt_image_loop(t_rt *rt)
{
  double	x;
  double	y;

  y = 0;
  while (y < rt->size_y)
    {
      x = 0;
      while (x < rt->size_x)
	{
	  rt_init_loop(rt, &rt->coord, x, y);
	  if (x > 0 && y > 0 && x < rt->size_x && y < rt->size_y &&
	      rt->aliasing > 0)
	    rt_aliasing(rt, x, y);
	  else
	    rt_loop(rt);
	  rt_reflex_trans(rt);
	  rt_pixel_put_to_image(rt, (int)x, (int)y);
	  x++;
	}
      mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
      y++;
    }
}
