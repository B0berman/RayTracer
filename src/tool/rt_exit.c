/*
** rt_exit.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_favar_a/MUL_2014_rtracer
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri May 29 19:25:18 2015 walbec_h
** Last update Fri May 29 19:40:27 2015 walbec_h
*/

#include	<stdlib.h>
#include	"neptune/system.h"

void		rt_exit(char *msg)
{
  t_system	*sys;

  sys = new_system(0, NULL, NULL);
  sys->out = sys->err;
  sys->print(sys, msg);
  exit(EXIT_FAILURE);
}
