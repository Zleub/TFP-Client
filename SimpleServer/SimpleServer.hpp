#ifndef SIMPLESERVER_HPP
#define SIMPLESERVER_HPP

#include <iostream>
#include <sstream>

extern "C" {
	#include "lua-5.3.0/src/lua.h"
	#include "lua-5.3.0/src/lualib.h"
	#include "lua-5.3.0/src/lauxlib.h"
}

class SimpleServer {
private:
	SimpleServer(SimpleServer const &);
	SimpleServer &	operator=(SimpleServer const &);

	lua_State *L;
public:
	SimpleServer(void);
	~SimpleServer(void);

	void		startCPPSide(void);
	std::string	startLuaSide(void);
	void		exec(std::string);
	void		run(void);
	void		getLuaError(int);
};

#endif
