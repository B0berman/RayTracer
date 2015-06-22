/*
** new_pixel.c for myriad in /home/zack/Projects/MUL_2014_rtracer/src/myriad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. mai 31 20:50:37 2015 Antoine Favarel
** Last update lun. juin 01 17:14:34 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"myriad.h"

t_pixel		*new_pixel(int x, int y, uint color)
{
  t_pixel	*pixel;

  if (!(pixel = malloc(sizeof(t_pixel))))
    return (NULL);
  pixel->x[0] = x;
  pixel->y[0] = y;
  pixel->color[0] = color;
  return (pixel);
}
