#ifndef _DEF_WAKE_ON_LAN_H_
# define _DEF_WAKE_ON_LAN_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

typedef	struct			s_socket
{
	struct sockaddr_in	socket_server;
	int					socket;
}						t_socket;

//ARGS
int						check_args(int, char *[]);

//SOCKET
int						create_socket(t_socket *);
int						send_magic_packet(t_socket *, char *);

#endif
