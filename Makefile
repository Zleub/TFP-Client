all: SimpleServer Client

re: fclean all

fclean:
	make -C SimpleServer fclean
	make -C Client fclean

clean:
	make -C SimpleServer clean
	make -C Client clean

SimpleServer:
	make -C SimpleServer

Client:
	make -C Client

.PHONY: all re fclean clean SimpleServer Client
