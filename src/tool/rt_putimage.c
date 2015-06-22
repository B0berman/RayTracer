/*
** rt_putimage.c for tool in /home/zack/Projects/MUL_2014_rtracer/src/tool
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. juin 07 15:52:24 2015 Antoine Favarel
** Last update dim. juin 07 16:10:20 2015 Antoine Favarel
*/

#ifndef		_XOPEN_SOURCE
# define	_XOPEN_SOURCE		500
#endif		/* !_XOPEN_SOURCE */

#include	<unistd.h>
#include	"myriad.h"
#include	"rt.h"

static void	stputpixelorder(t_rt *rt, t_pixel *pixel, size_t *it)
{
  int		i;

  i = -1;
  while (++i < 3)
  {
    rt->color = pixel->color[i];
    if (pixel->x[i] != -1)
    {
      rt_pixel_put_to_image(rt, pixel->x[i], pixel->y[i]);
      ++(*it);
    }
  }
}

void		putimage(t_rt *rt, t_dispatcher *dispatcher)
{
  t_list	*list;
  t_elem	*elem;
  t_pixel	*pixel;
  size_t	i;
  size_t	size;

  i = 0;
  size = rt->size_x * rt->size_y;
  while (i < size
      && (list = dispatcher->responds->popto(dispatcher->responds, size)))
  {
    list->rewind(list);
    while ((elem = list->next(list)))
    {
      pixel = (t_pixel*)elem->mem;
      stputpixelorder(rt, pixel, &i);
    }
    delete_list(list);
    mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
    usleep(1200);
  }
}
