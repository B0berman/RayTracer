/*
** sm_getmulong.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 15:46:11 2014 Antoine Favarel
** Last update jeu. avril 23 17:03:07 2015 Antoine Favarel
*/

#include	"strmut.h"

unsigned long	*sm_getmulong(char *str)
{
  unsigned long	*value;

  if (!str)
    return (NULL);
  if (!(value = malloc(sizeof(unsigned long))))
    exit(-1);
  (*value) = sm_getulong(str);
  return (value);
}
