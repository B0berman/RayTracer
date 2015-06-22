/*
** monad_update.c for monad in /home/zack/neptune/src/monad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 18:11:51 2015 Antoine Favarel
** Last update lun. juin 01 14:57:18 2015 Antoine Favarel
*/

#include	"monad.h"

static void	st_update(t_monad *this, t_list *data)
{
  this->data = data;
}

void		monad_update(t_monad *this, t_list *data)
{
  if (this)
    st_update(this, data);
}
