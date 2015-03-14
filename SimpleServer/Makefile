NAME =	SServer
SRC =	main.cpp \
		Lua.cpp \
		SimpleServer.cpp \
		Socket.cpp \
		Client.cpp
OBJ =	$(subst .cpp,.o,$(SRC))

CC =	g++
FLAGS =	-Wall -Werror -Wextra
LIBS =	-Ilua-5.3.0/src/ -Llua-5.3.0/src/ -llua

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

re: fclean all

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
