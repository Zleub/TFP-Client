//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Client:Lua
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-24 10:27:00
// :ddddddddddhyyddddddddddd: Modified: 2015-03-26 12:04:27
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <iostream>
#include <Lua.hpp>
#include <Client.hpp>

Lua::Lua(void)
{
	if (Client::Verb)
		std::cout << "Expect nothing. Live frugally" << std::endl;

	this->L = luaL_newstate();
	luaL_openlibs(this->L);
	this->init();
}

Lua::~Lua(void) {}

void		Lua::init(void)
{
	// this->exec("inspect = require 'inspect'");
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

std::string	Lua::getString(std::string name)
{
	lua_getglobal(L, name.c_str());
	if (!lua_isstring(L, -1))
		std::cerr << "No " << name << " string" << std::endl;
	else
		return lua_tostring(L, -1);
	return ("");
}

int			Lua::getNumber(std::string name)
{
	lua_getglobal(L, name.c_str());
	if (!lua_isnumber(L, -1))
		std::cerr << "No " << name << " number" << std::endl;
	else
		return lua_tonumber(L, -1);
	return (0);
}

Lua::Test	Lua::getVar(std::string name)
{

	(void)name;
	Lua::Test _u;
	_u._s = "Test";
	return (_u);
}

std::ostream &		operator<<(std::ostream & os, Lua::Test obj)
{
	(void)obj;
	return os << "This is ope surcharge" << std::endl;
}
