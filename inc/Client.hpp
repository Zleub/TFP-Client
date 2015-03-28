//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Client:Client
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-25 16:38:06
// :ddddddddddhyyddddddddddd: Modified: 2015-03-26 12:00:54
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef CLIENT_HPP
#define CLIENT_HPP

// #include <SFML/Graphics.hpp>
// #include <SFML/Network.hpp>

#include <iostream>
#include <Lua.hpp>
#include <Loader.hpp>
#include <Game.hpp>

class Client {
private:
	Client(Client const &);
	Client &	operator=(Client const &);

	Lua						_lua;
	Loader					_loader;
	Game					_game;
public:
	Client(void);
	~Client(void);

	/** \brief Verbosity state
	*
	*	defined in game.conf.lua */
	static bool				Verb;

	void	Start(void);
};

#endif
