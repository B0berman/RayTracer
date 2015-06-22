/*
** delete_dispatcher.c for dispatcher in /home/zack/neptune/src/clust/dispatcher
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 15:46:48 2015 Antoine Favarel
** Last update lun. juin 01 14:55:54 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"neptune/clust/dispatcher.h"

void		delete_dispatcher(t_dispatcher *dispatcher)
{
  uninit_dispatcher(dispatcher);
  if (dispatcher)
    free(dispatcher);
}
