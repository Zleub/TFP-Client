//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Socket
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-21 00:32:32
// :ddddddddddhyyddddddddddd: Modified: 2015-03-21 12:52:11
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Socket.hpp>
#include <SocketException.hpp>

Socket::Socket(void)
{
	if ((_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
		throw Socket::SocketException();
}

Socket::~Socket(void) {}

void	Socket::C_connect(void)
{
	struct sockaddr_in	serv_addr;

	_fd = socket(AF_INET, SOCK_DGRAM, 0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(4242);
	inet_aton("127.0.0.1", (struct in_addr *)&serv_addr.sin_addr.s_addr);

	if (connect(_fd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		std::cout << "test" << std::endl;
		throw Socket::SocketException();
	}
}

void	Socket::C_write(std::string str) const
{
	write(_fd, (str + "\n").c_str(), str.size() + 1);
}
