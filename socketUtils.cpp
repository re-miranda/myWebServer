#include "socketUtils.hpp"

int	newSocket( void ) {
	return (socket(AF_INET, SOCK_STREAM, 0));
}

void	setupIPV4Address(struct sockaddr_in * address, char * ip, int port) {
	address->sin_port = htons(80);
	address->sin_family = AF_INET;
	if (*ip)
		inet_pton(AF_INET, ip, &address->sin_addr.s_addr);
	else
		inet_pton(AF_INET, "127.0.0.1", &address->sin_addr.s_addr);
	return ;
}
