NAME =	Client
INCS =	$(subst .cpp,.hpp,$(SRC))
OBJ =	$(subst .cpp,.o,$(SRC))
SRC =	src/main.cpp\
		src/SocketException.cpp\
		src/Socket.cpp\
		src/Game.cpp\
		src/Player.cpp\

CC =	g++
FLAGS =	-Wall -Werror -Wextra
INC =	-Ilib/SFML-2.2/include -Iinc
LIBS =	-Llib/SFML-2.2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LIBS) -rpath lib/SFML-2.2/extlibs

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $< $(INC)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
