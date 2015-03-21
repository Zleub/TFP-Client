#ifndef SIMPLESERVER_HPP
#define SIMPLESERVER_HPP

#include <iostream>

#include "Lua.hpp"
#include "Socket.hpp"

class SimpleServer {
private:
	SimpleServer();
	SimpleServer(SimpleServer const &);
	SimpleServer &	operator=(SimpleServer const &);

	Lua			L;
	Socket		*s;
	std::string	host;
	int			port;
public:
	SimpleServer(std::string file = "conf");
	~SimpleServer(void);

	void		run(void);
};

#endif
