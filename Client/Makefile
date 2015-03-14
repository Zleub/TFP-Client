NAME =	Client
SRC =	main.cpp
OBJ =	$(subst .cpp,.o,$(SRC))

CC =	clang++
FLAGS =	-Wall -Werror -Wextra
INC =	-ISFML-2.2/include
LIBS =	-LSFML-2.2/lib -lsfml-graphics -lsfml-window -lsfml-system

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
