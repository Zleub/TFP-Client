NAME =	SimpleServer
SRC =	src/main.cpp \
		src/Lua.cpp \
		src/SimpleServer.cpp \
		src/Socket.cpp \
		src/Client.cpp
OBJ =	$(subst .cpp,.o,$(SRC))

CC =	g++
FLAGS =	-Wall -Werror -Wextra
INC =	-Iinc -Ilib/lua-5.3.0/src/
LIBS =	-Llib/lua-5.3.0/src/ -llua

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $< $(INC)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
