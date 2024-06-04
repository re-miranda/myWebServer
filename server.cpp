#include "socketUtils.hpp"

int	main( void ) {
	struct sockaddr_in		address;
	int						socketFD;
	int						connection;

	setupIPV4Address(&address, "", 2000);

	socketFD = newSocket();
	if (socketFD < 1)
		return (-1);

	connection = bind(socketFD, (struct sockaddr *)&address, sizeof(address));
	connection = connect(socketFD, (struct sockaddr *)&address, sizeof(address));
	if (connection == 0)
		std::cout << "Connection was sucessful" << std::endl;
	
	char	message[1024] = "GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";
	send(socketFD, message, strlen(message), 0);
	char	buffer[1024];
	recv(socketFD, buffer, sizeof(buffer), 0);
	std::cout << "response: \n" << buffer << std::endl;
	return (0);
}
