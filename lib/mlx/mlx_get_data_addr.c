/*
** mlx_get_data_addr.c for MiniLibX in raytraceur
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Aug 14 15:45:57 2000 Charlie Root
** Last update Mon Apr 27 11:07:18 2015 walbec_h
*/



#include	"mlx_int.h"


unsigned char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel,
			   int *size_line,int *endian)
{
  *bits_per_pixel = img->bpp;
  *size_line = img->size_line;
  *endian = img->image->byte_order;
  return (img->data);
}
