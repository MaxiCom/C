#include "wake_on_lan.h"

int		create_socket(t_socket *t_socket)
{
	int broadcastEnable=1;
	
	/*
		Create a socket 
			AF_INET = ipv4 format
			SOCK_DGRAM = Connectionless packet
			IPPROTO_UDP = protocol udp
	*/
	if ((t_socket->client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
		return (-1);
	//Enable broadcast	
	setsockopt(t_socket->client, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, \
		sizeof(broadcastEnable));	

	memset((char *)&(t_socket->server), 0, sizeof(t_socket->server));
	t_socket->server.sin_family = AF_INET;
	t_socket->server.sin_port = htons(9);

	//Convert socket_server into the server socket obviously
	if (inet_aton("192.168.1.255", &(t_socket->server.sin_addr)) == 0)
		return (-1);

	return (0);
}

int		send_magic_packet(t_socket *t_socket, char *mac_addr)
{
	char *coucou = "coucou";
	(void)mac_addr;

	sendto(t_socket->client, coucou, 6, 0, (struct sockaddr *)&(t_socket->server), \
		sizeof(t_socket->server));
	return (0);
}
