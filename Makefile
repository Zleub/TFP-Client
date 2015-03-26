NAME =	Client
INCS =	$(subst .cpp,.hpp,$(SRC))
OBJ =	$(subst .cpp,.o,$(SRC))
SRC =	src/main.cpp\
		src/Client.cpp\
		src/Lua.cpp\
		src/Game.cpp\
		src/Loader.cpp\
		src/Player.cpp\

CC		=	clang++
FLAGS	=	-Wall -Werror -Wextra

INC		=	-Iinc
INC		+=	-Ilib/SFML-2.2/include
INC		+=	-Ilib/lua-5.3.0/src/

LIBS	=	-Llib/SFML-2.2/lib
LIBS	+=	-lsfml-graphics
LIBS	+=	-lsfml-window
LIBS	+=	-lsfml-system
LIBS	+=	-lsfml-audio
LIBS	+=	-lsfml-network

LIBS	+=	-Llib/lua-5.3.0/src/
LIBS	+=	-llua


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
