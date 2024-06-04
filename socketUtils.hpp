#ifndef SOCKETUTILS_HPP
# define SOCKETUTILS_HPP

# include <cstring>
# include <iostream>
# include <sys/_endian.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

int		newSocket( void );
void	setupIPV4Address(struct sockaddr_in * address, char * ip, int port);

#endif
