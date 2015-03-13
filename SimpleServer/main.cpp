#include "SimpleServer.hpp"

int main(void)
{
	SimpleServer s;

	s.startCPPSide();
	s.run();
	return (0);
}
