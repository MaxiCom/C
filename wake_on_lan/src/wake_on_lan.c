#include "wake_on_lan.h"

void	display_help(char *binary_name)
{
	printf("usage: %s MAC_ADDRESS\n", binary_name);
}

int	create_socket(t_socket *t_socket, char *argv[])
{
	if ((t_socket->socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
		return (-1);
	
	memset((char *)&(t_socket->socket_server), 0, sizeof(t_socket->socket_server));
	t_socket->socket_server.sin_family = AF_INET;
	t_socket->socket_server.sin_port = htons(9);

	if (inet_aton(argv[1], &(t_socket->socket_server)) == 0)
		return (-1);

	return (0);
}

int		main(int argc, char *argv[])
{
	t_socket	t_socket;

	if (check_args(argc, argv) != 0)
		display_help(argv[0]);
	create_socket(&t_socket, argv);
	return (0);
}
