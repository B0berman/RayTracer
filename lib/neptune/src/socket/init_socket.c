/*
** init_socket.c for socket in /home/zack/neptune/src/socket
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 21:14:23 2015 Antoine Favarel
** Last update mar. juin 02 17:04:22 2015 Antoine Favarel
*/

#include	"neptune/socket.h"

static void	init_socket_methods(t_socket *socket)
{
  socket->open = &(socket_open);
}

static void	init_socket_values(t_socket *socket, int port)
{
  socket->port = port;
  socket->is_assync = 0;
  socket->counter = 0;
  pthread_cond_init(&socket->ready_writing, NULL);
  pthread_mutex_init(&socket->ready_mutex, NULL);
}

void		init_socket(t_socket *socket, char *addr, int port)
{
  if (socket)
  {
    init_io((void*)socket, addr);
    init_socket_methods(socket);
    init_socket_values(socket, port);
  }
}
