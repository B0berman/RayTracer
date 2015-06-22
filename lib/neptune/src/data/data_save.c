/*
** data_save.c for data in /home/zack/neptune/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 14:56:03 2015 Antoine Favarel
** Last update dim. mai 31 01:45:53 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"neptune/data.h"

static void	save_in_stream(t_data *this, t_io *stream)
{
  this->lock(this);
  this->magic_cmp = this->check(this);
  stream->lock(stream);
  if (stream->puts(stream, (char *)&this->size_of_mem, sizeof(size_t))
      == EXIT_FAILURE)
    return ;
  if (stream->puts(stream, (char *)&this->magic_cmp, sizeof(int))
      == EXIT_FAILURE)
    return ;
  if (stream->puts(stream, (char *)&this->id, sizeof(int))
      == EXIT_FAILURE)
    return ;
  if (stream->puts(stream, this->mem, this->size_of_mem)
      == EXIT_FAILURE)
    return ;
  stream->unlock(stream);
  this->unlock(this);
}

void		data_save(t_data *this, t_io *stream)
{
  if (this && stream)
    save_in_stream(this, stream);
}
