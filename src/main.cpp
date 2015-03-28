//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 22:14:10
// :ddddddddddhyyddddddddddd: Modified: 2015-03-26 12:01:01
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Client.hpp>

void launch(void)
{
	Client		client;

	client.Start();
}

int main(int argc, char* argv[])
{
	for (int i = 0; i < argc; ++i)
		if (std::string(argv[i]) == "-v") {
			std::cout << "VERBOSE MODE" << std::endl;
			Client::Verb = true;
		}
	launch();
}
