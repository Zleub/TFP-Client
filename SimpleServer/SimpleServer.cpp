#include "SimpleServer.hpp"

SimpleServer::SimpleServer() {}
SimpleServer::~SimpleServer() {}

void		SimpleServer::getLuaError(int error)
{
	if (error) {
		std::cerr << lua_tostring(this->L, -1) << std::endl;
		lua_pop(this->L, 1);  /* pop error message from the stack */
	}
}

std::string	SimpleServer::startLuaSide(void)
{
	return ("init = require 'init'; inspect = require 'inspect';");
}

void		SimpleServer::startCPPSide(void)
{
	this->L = luaL_newstate();
	luaL_openlibs(this->L);
	this->exec(this->startLuaSide());
}

void		SimpleServer::exec(std::string str)
{
	this->getLuaError(
		luaL_loadbuffer(this->L, str.c_str(), str.size(), "line")
		|| lua_pcall(this->L, 0, 0, 0)
	);
}

void		SimpleServer::run(void)
{
	std::string	buf;

	while (!std::cin.eof())
	{
		getline(std::cin, buf);
		std::cout << "parrot: " << buf << std::endl;
		this->exec(buf);
	}
}

