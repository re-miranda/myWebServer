#include "socketUtils.hpp"
#include <sys/socket.h>

int	main( void ) {
	int						socketFD;
	int						connection;
	struct sockaddr_in		server_address;
	unsigned int			server_address_size;
	struct sockaddr_in		client_address;
	unsigned int			client_address_size;

	socketFD = newSocket();
	if (socketFD < 1)
		return (-1);

	setupIPV4Address(&server_address, "", 2000);
	server_address_size = sizeof(server_address);

	connection = bind(socketFD, (struct sockaddr *)&server_address, sizeof(server_address));
	if (connection != 0)
		return (-2);
	std::cout << "Listening" << std::endl;

	connection = listen(socketFD, 10);

	setupIPV4Address(&client_address, "", 2000);
	client_address_size = sizeof(client_address);
	connection = accept(socketFD, (struct sockaddr *)&client_address, &client_address_size);
	if (connection < 0)
		std::cout << "Accept failed" << std::endl;

	char	buffer[1024];
	recv(connection, buffer, sizeof(buffer), 0);
	std::cout << "response: \n" << buffer << std::endl;
	
	shutdown(socketFD, SHUT_RDWR);
	

	return (0);
}
