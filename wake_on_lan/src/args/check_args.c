#include "wake_on_lan.h"

int		is_mac_address(char *mac_addr)
{
	int index;
	
    for(index = 0; index < 17; index++) {
        if(index % 3 != 2 && !isxdigit(mac_addr[index]))
            return (-1);
        if(index % 3 == 2 && mac_addr[index] != ':')
            return (-1);
    }
    if(mac_addr[17] != '\0')
        return (-1);
    return (0);
}

int		check_args(int argc, char *argv[])
{
	if (argc != 2 || is_mac_address(argv[1]) != 0)
		return (-1);	
	return (0);
}
