NAME =	Client
SRC =	main.cpp
OBJ =	$(subst .cpp,.o,$(SRC))

CC =	clang++
FLAGS =	-Wall -Werror -Wextra
INC =	-ISFML-2.2/include
LIBS =	-LSFML-2.2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

DYLD_LIBRARY_PATH =	SFML-2.2/lib

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
