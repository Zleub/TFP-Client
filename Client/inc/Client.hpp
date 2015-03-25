//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Client:Client
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-25 16:38:06
// :ddddddddddhyyddddddddddd: Modified: 2015-03-25 20:45:38
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <Game.hpp>
#include <Lua.hpp>

class Client {
private:
	Client(Client const &);
	Client &	operator=(Client const &);

	Lua						_lua;
	Game					*_game;
public:
	Client(void);
	~Client(void);

	void	Start(void);
};

#endif
