#ifndef LUA_HPP
#define LUA_HPP

#include <iostream>

extern "C" {
	#include "lua-5.3.0/src/lua.h"
	#include "lua-5.3.0/src/lualib.h"
	#include "lua-5.3.0/src/lauxlib.h"
}

class	Lua {
private:
	Lua(Lua const &);
	Lua &	operator=(Lua const &);

	lua_State	*L;
public:
	Lua(void);
	~Lua(void);

	void		init(void);
	void		exec(std::string);
	void		getError(int);
	std::string	get_Gstring(std::string);
	int			get_Gnumber(std::string);
};

#endif
