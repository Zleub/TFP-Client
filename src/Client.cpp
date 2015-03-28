//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Client:Client
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-25 16:38:37
// :ddddddddddhyyddddddddddd: Modified: 2015-03-26 10:22:00
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Client.hpp>

bool	Client::Verb = false;

Client::Client(void)
{
	if (Client::Verb)
		std::cout << "To need of pity" << std::endl;

	_lua.exec("require 'conf.TFP'");
	_lua.exec("test = Modules[1]");
}

Client::~Client(void) {}

void	Client::Start(void) {
	// _lua.exec("test = 5");
	std::cout << _lua.getVar("test") << std::endl;
	_game.run();
}
