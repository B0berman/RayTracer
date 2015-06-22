/*
** myriad_dispatcher.c for myriad in /home/zack/Projects/MUL_2014_rtracer/src/myriad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. mai 31 21:15:41 2015 Antoine Favarel
** Last update dim. mai 31 21:17:27 2015 Antoine Favarel
*/

#include	"myriad.h"

t_dispatcher	*myriad_dispatcher(t_rt *rt, int port)
{
  t_dispatcher	*dispatcher;

  dispatcher = new_dispatcher("127.0.0.1/dispatcher", port);
  dispatcher->data = myriad_setrt(rt);
  dispatcher->open(dispatcher);
  return (dispatcher);
}
