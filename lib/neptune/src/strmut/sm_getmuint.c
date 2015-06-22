/*
** sm_getmuint.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 15:43:16 2014 Antoine Favarel
** Last update jeu. avril 23 17:03:05 2015 Antoine Favarel
*/

#include	"strmut.h"

unsigned int	*sm_getmuint(char *str)
{
  unsigned int	*value;

  if (!str)
    return (NULL);
  if (!(value = malloc(sizeof(unsigned int))))
    exit(-1);
  (*value) = sm_getuint(str);
  return (value);
}
