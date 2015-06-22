/*
** myriad.h for include in /home/zack/Projects/MUL_2014_rtracer/include
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. mai 31 20:41:14 2015 Antoine Favarel
** Last update lun. juin 01 17:14:05 2015 Antoine Favarel
*/

#ifndef		MYRIAD_H_
# define	MYRIAD_H_

# include	"rt.h"
# include	"neptune/clust/dispatcher.h"
# include	"neptune/clust/manager.h"

typedef	struct	s_pixel
{
  int		x[3];
  int		y[3];
  uint		color[3];
}		t_pixel;

/* TOOL */
t_pixel		*new_pixel(int x, int y, uint color);

/* MANAGER */
t_data		*myriad_actor(t_monad *this, t_data *data);
t_rt		*myriad_getrt(t_monad *this);
t_manager	*myriad_manager(char *host, int port);

/* DISPATCHER */
t_list		*myriad_setrt(t_rt *rt);
t_dispatcher	*myriad_dispatcher(t_rt *rt, int port);
void		myriad_putorder(t_rt *rt, t_dispatcher *dispatcher);

#endif		/* !MYRIAD_H_ */

