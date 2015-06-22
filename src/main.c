/*
** main.c for src in /home/zack/Projects/MUL_2014_rtracer/src
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. févr. 22 02:07:19 2015 Antoine Favarel
** Last update Thu Jun 11 13:40:10 2015 walbec_h
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>
#include	"neptune/list.h"
#include	"neptune/strmut.h"
#include	"myriad.h"
#include	"rt.h"

void		clean(t_rt *rt)
{
  int		x;
  int		y;

  y = -1;
  while (++y < (int)rt->size_y)
  {
    x = -1;
    while (++x < (int)rt->size_x)
    {
      rt->color = 0x000000;
      rt_pixel_put_to_image(rt, x, y);
    }
  }
  mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
}

void		printer(t_dispatcher *dis, t_rt *rt)
{
  clean(rt);
  myriad_putorder(rt, dis);
  putimage(rt, dis);
  mlx_clear_window(rt->mlx_ptr, rt->win_ptr);
}

void		loading(t_rt *rt, char **av)
{
  t_io		*file;

  file = new_io(av[1]);
  if (file->open(file) == EXIT_FAILURE)
    exit(EXIT_FAILURE);
  rt->objects->load(rt->objects, file);
  if (rt->objects->length == 0)
    exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
  t_rt		*rt;
  t_dispatcher	*dispatcher;

  if (ac != 2)
    rt_exit("Invalid number of parameter\nuse './rt (aliasing)'\n");
  rt = rt_init("RayTracer", 800, 800);
  rt->obj = NULL;
  rt->size_x = 800;
  rt->size_y = 800;
  rt->aliasing = 0;
  rt_init_test(rt);
  rt->objects = new_list();
  loading(rt, av);
  dispatcher = myriad_dispatcher(rt, 9595);
  myriad_manager("127.0.0.1", 9595);
  printer(dispatcher, rt);
  mlx_mouse_hook(rt->win_ptr, rt_ptr_mouse, rt);
  mlx_key_hook(rt->win_ptr, rt_ptr_key, rt);
  mlx_expose_hook(rt->win_ptr, rt_ptr_expose, rt);
  mlx_loop(rt->mlx_ptr);
  return (0);
}
