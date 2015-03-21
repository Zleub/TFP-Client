//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:SocketException
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-21 01:12:16
// :ddddddddddhyyddddddddddd: Modified: 2015-03-21 02:54:10
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef SOCKETEXCEPTION_HPP
#define SOCKETEXCEPTION_HPP

#include <Socket.hpp>

class Socket::SocketException : public std::exception {
public:
		SocketException(void);
		~SocketException(void) throw();
		SocketException(SocketException const &);
		SocketException &	operator=(SocketException const &);

		virtual char const * what(void) const throw();
};

#endif
