#include "wake_on_lan.h"

int		create_socket(t_socket *t_socket)
{
	if ((t_socket->socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
		return (-1);
	
	memset((char *)&(t_socket->socket_server), 0, sizeof(t_socket->socket_server));
	t_socket->socket_server.sin_family = AF_INET;
	t_socket->socket_server.sin_port = htons(9);

	if (inet_aton("192.168.1.14", &(t_socket->socket_server.sin_addr)) == 0)
		return (-1);

	return (0);
}

int		send_magic_packet(t_socket *t_socket, char *mac_addr)
{
	int first_loop = -1;
	char	*ff = "FF";

	(void)mac_addr;
	while (++first_loop <= 5)
		sendto(t_socket->socket, ff, 2, 0, (struct sockaddr *)&(t_socket->socket_server), sizeof(t_socket->socket_server));
	return (0);
}
