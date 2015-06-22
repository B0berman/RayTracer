/*
** list_save.c for list in /home/zack/neptune/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 22:00:53 2015 Antoine Favarel
** Last update mer. juin 03 16:47:05 2015 Antoine Favarel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"neptune/list.h"

static void	bputs(char *buffer, size_t *it, char *mem, size_t size)
{
  size_t	i;

  i = 0;
  while (i < size)
  {
    buffer[*it + i] = mem[i];
    i++;
  }
  *it += size;
}

static void	bputs_elem(t_elem *this, char *buffer, size_t *it)
{
  this->lock(this);
  this->magic_cmp = this->check(this);
  bputs(buffer, it, (char *)&this->size_of_mem, sizeof(size_t));
  bputs(buffer, it, (char *)&this->magic_cmp, sizeof(int));
  bputs(buffer, it, (char *)&this->id, sizeof(int));
  bputs(buffer, it, this->mem, this->size_of_mem);
  this->unlock(this);
}

static size_t	counterbitte(t_list *this)
{
  size_t	size;
  t_elem	*elem;

  size = sizeof(size_t) * 2 + sizeof(int);
  this->rewind(this);
  while ((elem = this->next(this)))
    size += sizeof(size_t) + sizeof(int) * 2 + elem->size_of_mem;
  return (size);
}

static char	*save_in_stream(t_list *this, t_io *stream, size_t *it)
{
  size_t	size;
  size_t	size2;
  char		*buffer;

  this->lock(this);
  size = counterbitte(this);
  size2 = size - (sizeof(size_t) * 2 + sizeof(int));
  this->magic_cmp = this->check(this);
  if (!(buffer = malloc(size)))
  {
    this->unlock(this);
    return (NULL);
  }
  bputs(buffer, it, (char *)&this->length, sizeof(size_t));
  bputs(buffer, it, (char *)&this->magic_cmp, sizeof(int));
  bputs(buffer, it, (char *)&size2, sizeof(size_t));
  return (buffer);
}

void		list_save(t_list *this, t_io *stream)
{
  t_elem	*elem;
  size_t	size;
  char		*buffer;
  size_t	it;

  size = counterbitte(this);
  it = 0;
  if (!this && !stream)
    return ;
  if (!(buffer = save_in_stream(this, stream, &it)))
    return ;
  this->rewind(this);
  while ((elem = this->next(this)))
    bputs_elem(elem, buffer, &it);
  this->unlock(this);
  stream->lock(stream);
  stream->puts(stream, buffer, size);
  stream->unlock(stream);
  free(buffer);
}
