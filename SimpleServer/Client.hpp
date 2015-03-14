#ifndef CLIENT_HPP
#define CLIENT_HPP

extern "C" {
	#include <netinet/ip.h>
	#include <arpa/inet.h>
	#include <sys/types.h>
}


class Client {
private:
	Client(Client const &);
	Client &	operator=(Client const &);

	int				fd;
	struct sockaddr	addr;
	socklen_t		addr_size;

public:
	Client(void);
	~Client(void);

	void				setFd(int);
	int					getFd(void);
	struct sockaddr *	getAddr(void);
	socklen_t *			getAddrsize(void);
};

#endif
