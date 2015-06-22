/*
** server.h for neptune in /home/zack/neptune/include/neptune
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 18:34:18 2015 Antoine Favarel
** Last update mar. juin 02 17:03:01 2015 Antoine Favarel
*/

#ifndef			NEP_SERVER_H_
# define		NEP_SERVER_H_

# include		"neptune/list.h"
# include		"neptune/socket.h"

typedef	struct		s_s_arg
{
  void			*server;
  void			*socket;
}			t_s_arg;

typedef	struct		s_server
{
  /*			< t_socket*/
  char			*src;
  int			fd;
  char			*buffer;
  size_t		buffsize;
  int			is_assync;
  pthread_mutex_t	mutex;
  pthread_mutexattr_t	attr;
  int			(*open)(struct s_server *);
  int			(*puts)(struct s_server *, char *buffer, size_t size);
  int			(*gets)(struct s_server *, char *buffer, size_t size);
  char			*(*nextline)(struct s_server *, char separator);
  int			(*close)(struct s_server *);
  void			(*gst_close)(struct s_server *);
  void			(*gst_recv)(struct s_server *, char *buf, size_t size);
  void			(*assync)(struct s_server *, int on_off);
  void			(*lock)(struct s_server *);
  void			(*unlock)(struct s_server *);
  int			port;
  pthread_t		main;
  pthread_cond_t	read_writing;
  int			counter;
  pthread_mutex_t	ready_mutex;
  /*			< new*/
  t_list		*clients;
  void			*(*gst_connection)(void *arg);
  void			*(*gst_disconnection)(void *arg);
}			t_server;

t_server		*new_server(char *addr, int port);
void			init_server(t_server *, char *ad, int port);
void			*server_main(void *this);
int			server_open(t_server *this);
int			server_close(t_server *this);
void			uninit_server(t_server *server);
void			delete_server(t_server *server);

#endif			/* !NEP_SERVER_H_ */

