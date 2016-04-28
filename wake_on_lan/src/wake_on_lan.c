#include "wake_on_lan.h"

int		display_help(char *binary_name)
{
	printf("usage: %s MAC_ADDRESS\n", binary_name);
	return (-1);
}

int		quit_with_prompt(char *message)
{
	printf("%s", message);
	return (-1);
}

int		main(int argc, char *argv[])
{
	t_socket	t_socket;

	if (check_args(argc, argv) != 0)
		return (display_help(argv[0]));
	if (create_socket(&t_socket) != 0)
		return (quit_with_prompt("failed to create socket"));	
	if (send_magic_packet(&t_socket, argv[1]) != 0)
		return (quit_with_prompt("failed to send magic packet"));
	close(t_socket.client);
	return (0);
}
