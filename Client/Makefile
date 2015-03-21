NAME =	Client
OBJ =	$(subst .cpp,.o,$(SRC))
SRC =	main.cpp\
		SocketException.cpp\
		Socket.cpp\
		Game.cpp\
		Player.cpp\

CC =	g++
FLAGS =	-Wall -Werror -Wextra
INC =	-ISFML-2.2/include -I.
LIBS =	-LSFML-2.2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LIBS) -rpath SFML-2.2/extlibs

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $< $(INC)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
