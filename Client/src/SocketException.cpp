//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:SocketException
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-21 01:08:59
// :ddddddddddhyyddddddddddd: Modified: 2015-03-21 02:55:40
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <SocketException.hpp>

Socket::SocketException::SocketException (void) {}
Socket::SocketException::~SocketException (void) throw() {}

Socket::SocketException::SocketException(SocketException const & src) {
	if (this == &src)
		return;
	*this = src;
}

Socket::SocketException &	Socket::SocketException::SocketException::operator=(SocketException const &) {
	return *this;
}

char const *	Socket::SocketException::what (void) const throw()
{
	return "SocketException";
}
