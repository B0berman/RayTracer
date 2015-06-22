/*
** myriad_putorder.c for myriad in /home/zack/Projects/MUL_2014_rtracer/src/myriad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. mai 31 21:17:41 2015 Antoine Favarel
** Last update dim. juin 07 15:45:56 2015 Antoine Favarel
*/

#include	"myriad.h"

void		myriad_putorder(t_rt *rt, t_dispatcher *dispatcher)
{
  int		x;
  int		y;
  t_pixel	*pixel;

  y = 0;
  while (y < (int)rt->size_y)
  {
    x = 0;
    while (x < (int)rt->size_x)
    {
      pixel = new_pixel(x, y, 0xFFFFFF);
      pixel->x[1] = (x + 1 >= (int)rt->size_x) ? -1 : x + 1;
      pixel->y[1] = (x + 1 >= (int)rt->size_x) ? -1 : y;
      pixel->x[2] = (x + 2 >= (int)rt->size_x) ? -1 : x + 2;
      pixel->y[2] = (x + 2 >= (int)rt->size_x) ? -1 : y;
      dispatcher->orders->push(dispatcher->orders,
	  _wrap(pixel, sizeof(t_pixel)));
      x += 3;
    }
    y++;
  }
}
