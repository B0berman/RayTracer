/*
** sm_cat.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Sun Nov 30 20:59:23 2014 Antoine Favarel
** Last update jeu. avril 23 17:02:24 2015 Antoine Favarel
*/

#include	"strmut.h"

char		*sm_cat(char *s1, char *s2)
{
  size_t	size;
  int		ite;
  int		itej;
  char		*n_str;

  ite = -1;
  itej = -1;
  if (!s1 && !s2)
    return (NULL);
  if (s1 && !s2)
    return (sm_dup(s1));
  if (s2 && !s1)
    return (sm_dup(s2));
  size = sm_len(s1) + sm_len(s2);
  if (!(n_str = malloc(sizeof(char) * (size + 1))))
    exit(-1);
  while (s1[++ite])
    n_str[ite] = s1[ite];
  while (s2[++itej])
    {
      n_str[ite] = s2[itej];
      ite++;
    }
  n_str[ite] = '\0';
  return (n_str);
}
