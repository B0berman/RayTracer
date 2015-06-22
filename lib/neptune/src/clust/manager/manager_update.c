/*
** manager_update.c for manager in /home/zack/neptune/src/clust/manager
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 13:51:11 2015 Antoine Favarel
** Last update lun. juin 01 14:54:50 2015 Antoine Favarel
*/

#include	"neptune/clust/manager.h"

void		manager_update(t_manager *this, t_list *data)
{
  t_elem	*elem;
  t_monad	*monad;

  this->monads->rewind(this->monads);
  while ((elem = this->monads->next(this->monads)))
    if ((monad = elem->mem))
      monad->update(monad, data);
}
