/*
** rt_aliasing.c for tool in /home/zack/Projects/MUL_2014_rtracer/src/tool
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Apr  3 13:50:53 2015 hugo walbecq
** Last update dim. juin 07 13:40:03 2015 Antoine Favarel
*/

#include	"neptune/io.h"
#include	"neptune/strmut.h"
#include	"rt.h"

static int	check_ret(t_rt *rt, uint *col, int i)
{
  int		size_bim;
  int		coef;

  col[i] = rt->color;
  if (rt->aliasing < 4)
    return (0);
  size_bim = (rt->aliasing * rt->aliasing) / 2;
  coef = size_bim / 4;
  if (i >= size_bim
      && col[i - coef] == rt->color
      && col[i - coef * 2] == rt->color
      && col[i - coef * 3] == rt->color
      && col[i - coef * 4] == rt->color)
    {
      rt->color = rt_average(col, i);
      free(col);
      return (1);
    }
  return (0);
}

void		rt_aliasing(t_rt *rt, double x, double y)
{
  int		i;
  double	x1;
  double	y1;
  double	coef;
  uint		*col;

  i = -1;
  col = malloc(sizeof(unsigned int) * (pow(rt->aliasing + 1, 2)));
  coef = (1 / (double)rt->aliasing);
  x1 = x - 1;
  while (x1 <= x)
    {
      y1 = y - 1;
      while (y1 <= y)
	{
	  rt_init_loop(rt, &rt->coord, x1, y1);
	  rt_loop(rt);
	  if (check_ret(rt, col, ++i))
	    return ;
	  y1 += coef;
	}
      x1 += coef;
    }
  rt->color = rt_average(col, i);
  free(col);
}
