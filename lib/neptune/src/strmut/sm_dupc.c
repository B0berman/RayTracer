/*
** sm_dupc.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 04:11:47 2014 Antoine Favarel
** Last update jeu. avril 23 17:02:41 2015 Antoine Favarel
*/

#include	"strmut.h"

char		*sm_dupc(char c)
{
  char		*s;

  if (!(s = malloc(sizeof(char) * 2)))
    exit(-1);
  s[0] = c;
  s[1] = '\0';
  return (s);
}
