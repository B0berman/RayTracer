/*
** sm_getmlong.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 15:44:59 2014 Antoine Favarel
** Last update jeu. avril 23 17:03:02 2015 Antoine Favarel
*/

#include	"strmut.h"

long		*sm_getmlong(char *str)
{
  long		*value;

  if (!str)
    return (NULL);
  if (!(value = malloc(sizeof(long))))
    exit(-1);
  (*value) = sm_getlong(str);
  return (value);
}
