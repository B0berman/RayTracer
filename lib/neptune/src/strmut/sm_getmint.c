/*
** sm_getmint.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 15:40:50 2014 Antoine Favarel
** Last update jeu. avril 23 17:03:00 2015 Antoine Favarel
*/

#include	"strmut.h"

int		*sm_getmint(char *str)
{
  int		*value;

  if (!str)
    return (NULL);
  if (!(value = malloc(sizeof(int))))
    exit(-1);
  (*value) = sm_getint(str);
  return (value);
}
