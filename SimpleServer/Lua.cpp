#include "Lua.hpp"

Lua::Lua(void)
{
	this->L = luaL_newstate();
	luaL_openlibs(this->L);
	this->init();
}

Lua::~Lua(void) {}

void		Lua::init(void)
{
	// this->exec("init = require 'init'");
	this->exec("inspect = require 'inspect'");
}

void		Lua::exec(std::string str)
{
	this->getError(
		luaL_loadbuffer(this->L, str.c_str(), str.size(), "line")
		|| lua_pcall(this->L, 0, 0, 0)
	);
}

void		Lua::getError(int error)
{
	if (error)
	{
		std::cerr << lua_tostring(this->L, -1) << std::endl;
		lua_pop(this->L, 1);  /* pop error message from the stack */
	}
}

std::string	Lua::get_Gstring(std::string name)
{
	lua_getglobal(L, name.c_str());
	if (!lua_isstring(L, -1))
		std::cerr << "No " << name << " number" << std::endl;
	else
		return lua_tostring(L, -1);
	return ("");
}

int			Lua::get_Gnumber(std::string name)
{
	lua_getglobal(L, name.c_str());
	if (!lua_isnumber(L, -1))
		std::cerr << "No " << name << " number" << std::endl;
	else
		return lua_tonumber(L, -1);
	return (0);
}
