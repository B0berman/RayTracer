/*
** main_slave.c for src in /home/zack/Projects/MUL_2014_rtracer/src
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. juin 01 02:15:00 2015 Antoine Favarel
** Last update dim. juin 07 15:41:23 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"myriad.h"
#include	"neptune/system.h"

int		main(int ac, char **av)
{
  t_manager	*manager;
  t_system	*sys;
  char		c;

  if (ac != 2)
    return (EXIT_FAILURE);
  if (!(manager = myriad_manager(av[1], 9595)))
  {
    sys = new_system(0, NULL, NULL);
    sys->print(sys, "Echec de connection au serveur!\n");
    exit(-1);
  }
  read(0, &c, 1);
  return (0);
}
