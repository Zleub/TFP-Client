#include "SimpleServer.hpp"

int main(void)
{
	SimpleServer s("conf");

	s.run();
	return (0);
}
