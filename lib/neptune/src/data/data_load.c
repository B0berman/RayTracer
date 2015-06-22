/*
** data_load.c for data in /home/zack/neptune/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 15:20:51 2015 Antoine Favarel
** Last update dim. mai 31 01:18:27 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"neptune/data.h"

int		data_load(t_data *this, t_io *stream)
{
  if (!this || !stream)
    return (EXIT_FAILURE);
  if (stream->gets(stream, (char *)&this->size_of_mem, sizeof(size_t))
      ==  EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (!(this->mem = malloc(this->size_of_mem)))
    return (EXIT_FAILURE);
  if (stream->gets(stream, (char *)&this->magic_cmp, sizeof(int))
      == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (stream->gets(stream, (char *)&this->id, sizeof(int))
      == EXIT_FAILURE)
    return (EXIT_FAILURE);
  this->is_local = 1;
  if (stream->gets(stream, this->mem, this->size_of_mem) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (this->magic_cmp != this->check(this))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
