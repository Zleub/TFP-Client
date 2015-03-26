//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Client:Client
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-25 16:38:37
// :ddddddddddhyyddddddddddd: Modified: 2015-03-25 21:01:30
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Client.hpp>

Client::Client(void)
{
	_game = new Game(_lua);
	_lua.exec("require 'TFP'");
	_lua.exec("test = Modules[1]");
}

Client::~Client(void) {}

void	Client::Start(void) {
	// _lua.exec("test = 5");
	std::cout << _lua.getString("test") << std::endl;
	_game->run();
}
