/*
** myriad_manager.c for myriad in /home/zack/Projects/MUL_2014_rtracer/src/myriad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. mai 31 21:08:31 2015 Antoine Favarel
** Last update lun. juin 01 17:43:06 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"myriad.h"

t_manager	*myriad_manager(char *host, int port)
{
  t_manager	*manager;

  manager = new_manager(host, port, 8);
  manager->actor = &myriad_actor;
  if (manager->open(manager) == EXIT_FAILURE)
    return (NULL);
  return (manager);
}
