/*
** init_data.c for data in /home/zack/neptune/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 16:28:35 2015 Antoine Favarel
** Last update dim. mai 31 00:25:41 2015 Antoine Favarel
*/

#include	"data.h"

void		init_data_methods(t_data *data)
{
  data->set_mem = &(data_set_mem);
  data->set_dupmem = &(data_set_dupmem);
  data->save = &(data_save);
  data->load = &(data_load);
  data->check = &(data_check);
  data->x = &(data_x);
  data->lock = &(data_lock);
  data->unlock = &(data_unlock);
}

void		init_data_values(t_data *data)
{
  data->size_of_mem = 0;
  data->magic_cmp = 0;
  data->is_local = 0;
  data->mem = NULL;
  data->id = 0;
  pthread_mutex_init(&data->mutex, NULL);
}

void		init_data(t_data *data)
{
  if (data)
  {
    init_data_methods(data);
    init_data_values(data);
  }
}
