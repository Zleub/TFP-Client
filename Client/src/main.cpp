//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 22:14:10
// :ddddddddddhyyddddddddddd: Modified: 2015-03-21 12:00:24
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <SFML/Graphics.hpp>

#include <Game.hpp>
#include <Socket.hpp>

int main(void)
{
	Game	game;
	Socket	s;

	try {
		s.C_connect();
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}

	s.C_write("request");
	game.run();
}
