//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Socket
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-21 00:22:33
// :ddddddddddhyyddddddddddd: Modified: 2015-03-21 11:27:30
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <iostream>

extern "C" {
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <arpa/inet.h>
}

class Socket {
private:
	Socket(Socket const &);
	Socket &	operator=(Socket const &);

	int			_fd;
public:
	class SocketException;

	Socket(void);
	~Socket(void);

	void	C_connect(void);
};

#endif
