/*
** rt_init.c for init in /home/zack/Projects/MUL_2014_rtracer/src/init
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue May  5 16:03:50 2015 walbec_h
** Last update lun. juin 01 01:55:30 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"rt.h"

t_rt		*rt_init(char *title, uint size_x, uint size_y)
{
  t_rt		*rt;

  if (!(rt = malloc(sizeof(t_rt))))
    rt_exit("error with malloc\n");
  if ((rt->mlx_ptr = mlx_init()) == NULL)
    rt_exit("env -i? Is it a joke?\n");
  rt->img_ptr = mlx_new_image(rt->mlx_ptr, size_x, size_y);
  rt->win_ptr = mlx_new_window(rt->mlx_ptr, size_x, size_y, title);
  rt->data = mlx_get_data_addr(rt->img_ptr, &rt->bpp,
			       &rt->size_line, &rt->endian);
  return (rt);
}
