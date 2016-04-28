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
	char			tosend[102];
	unsigned int	int_mac_array[6];
	char		mac_array[6];
	int			index;

	if (sscanf(mac_addr, "%x:%x:%x:%x:%x:%x", &int_mac_array[0], \
		&int_mac_array[1], &int_mac_array[2], &int_mac_array[3], \
			&int_mac_array[4], &int_mac_array[5]) < 6)
		return (-1);
	for (index = 0; index < 6; index++) {
		mac_array[index] = (unsigned char)int_mac_array[index];
	}
	for(index = 0; i < 6; i++) {
		tosend[i] = 0xFF;
	}
	for(index = 1; i <= 16; i++) {
		memcpy(&tosend[i * 6], &mac_array, 6 * sizeof(unsigned char));
	}
	sendto(t_socket->client, tosend, 102, 0, (struct sockaddr *)&(t_socket->server), \
		sizeof(t_socket->server));
	return (0);
}
