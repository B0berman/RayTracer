/*
** list_load.c for list in /home/zack/neptune/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 22:06:42 2015 Antoine Favarel
** Last update lun. juin 01 00:26:32 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"neptune/list.h"

static void	bgets(char *buffer, int *it, char *mem, size_t size)
{
  size_t	i;

  i = 0;
  while (i < size)
  {
    mem[i] = buffer[*it + i];
    i++;
  }
  *it += size;
}

static int	bgets_elem(t_elem *this, char *buffer, int *it)
{
  this->lock(this);
  bgets(buffer, it, (char *)&this->size_of_mem, sizeof(size_t));
  bgets(buffer, it, (char *)&this->magic_cmp, sizeof(int));
  bgets(buffer, it, (char *)&this->id, sizeof(int));
  if (!(this->mem = malloc(this->size_of_mem)))
  {
    this->unlock(this);
    return (EXIT_FAILURE);
  }
  bgets(buffer, it, this->mem, this->size_of_mem);
  this->unlock(this);
  if (this->check(this) == this->magic_cmp)
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

static int	slist_load(t_list *this, t_io *stream)
{
  int		i;
  int		it;
  size_t	length;
  char		*buffer;
  t_elem	*elem;
  size_t	size;

  i = -1;
  length = 0;
  it = 0;
  stream->gets(stream, (char *)&length, sizeof(size_t));
  stream->gets(stream, (char *)&this->magic_cmp, sizeof(int));
  stream->gets(stream, (char *)&size, sizeof(size_t));
  if (!(buffer = malloc(size)))
    return (EXIT_FAILURE);
  stream->gets(stream, buffer, size);
  while (++i < (int)length)
    if ((elem = new_elem()) && bgets_elem(elem, buffer, &it) == EXIT_SUCCESS)
      this->push(this, elem);
    else
      return (EXIT_FAILURE);
  free(buffer);
  if (this->magic_cmp != this->check(this))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		list_load(t_list *this, t_io *stream)
{
  if (!this || !stream)
    return (EXIT_FAILURE);
  return (slist_load(this, stream));
}
