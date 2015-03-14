#include "Client.hpp"

Client::Client(void) {}
Client::~Client(void) {}

void				Client::setFd(int fd) { this->fd = fd; }
int					Client::getFd(void) { return this->fd; }
struct sockaddr *	Client::getAddr(void) { return &(this->addr); }
socklen_t *			Client::getAddrsize(void) { return &(this->addr_size); }
