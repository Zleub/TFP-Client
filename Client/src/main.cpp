//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 22:14:10
// :ddddddddddhyyddddddddddd: Modified: 2015-03-22 18:29:01
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <Game.hpp>

int main(void)
{
	Game	game;
	sf::UdpSocket	socket;

	if (!socket.bind(4242))
	{
		std::cout << "bind not successful" << std::endl;
		return -1;
	}

	std::string message = "Hi, I am " + sf::IpAddress::getLocalAddress().toString() + "\n";
	socket.send(message.c_str(), message.size() + 2, "127.0.0.1", 4242);
	game.run();
}
