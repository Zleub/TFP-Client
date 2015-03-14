#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <iostream>
#include <cstring>

#include "Client.hpp"
#include "Lua.hpp"

extern "C" {
	#include <unistd.h>
	#include <sys/time.h>
	#include <sys/types.h>
	#include <netinet/ip.h>
	#include <arpa/inet.h>
}

class Socket {
private:
	Socket(void);
	Socket(Socket const &);
	Socket &	operator=(Socket const &);

	int					fd;
	struct sockaddr_in	my_addr;
	fd_set				active_fd_set;
	fd_set				read_fd_set;

	Lua					*L;
public:
	Socket(std::string, int);
	~Socket(void);

	void				setLua(Lua *);
	int					getFd(void);
	void				_select(void);
	Client &			_accept(void);
	int					_read(int);
};

#endif
