//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Client:Loader
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-25 16:19:23
// :ddddddddddhyyddddddddddd: Modified: 2015-03-26 10:16:15
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Loader.hpp>
#include <Client.hpp>

Loader::Loader(void)
{
	if (Client::Verb)
		std::cout << "On surprise." << std::endl;
}
Loader::~Loader(void) {}

