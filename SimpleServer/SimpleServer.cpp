#include "SimpleServer.hpp"

SimpleServer::SimpleServer(std::string file = "conf")
{
	L.exec(file + " = require '" + file + "'");
	if (L.get_Gstring("host") == "" || L.get_Gnumber("port") == 0)
		std::cerr << "Not able to create socket" << std::endl;
	else
		this->s = new Socket(L.get_Gstring("host"), L.get_Gnumber("port"));
}

SimpleServer::~SimpleServer() {}

void		SimpleServer::run(void)
{
	this->s->setLua(&L);

	while (!std::cin.eof())
	{
		this->s->_select();
	}
}

