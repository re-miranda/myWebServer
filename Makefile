NAME_CLIENT = client
NAME_SERVER = server

SRC_COMMON = socketUtils.cpp
SRC_CLIENT = client.cpp $(SRC_COMMON)
SRC_SERVER = server.cpp $(SRC_COMMON)

CXX = c++

all: $(NAME_CLIENT) $(NAME_SERVER)


run:
	./client
	./server

$(NAME_CLIENT): $(SRC_CLIENT)
	$(CXX) -o $@ $(SRC_CLIENT)

$(NAME_SERVER): $(SRC_SERVER)
	$(CXX) -o $@ $(SRC_SERVER)

clean:

fclean: clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re run
