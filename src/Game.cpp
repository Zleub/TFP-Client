//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 23:44:55
// :ddddddddddhyyddddddddddd: Modified: 2015-04-04 02:27:01
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Game.hpp>
#include <Client.hpp>

int				Game::Width = 800;
int				Game::Height = 600;
std::string		Game::Host = "127.0.0.1";
int				Game::Port = 4242;

Game::Game (void)
{
	if (Client::Verb)
		std::cout << "Game Constructor" << std::endl;

	_window = new sf::RenderWindow(sf::VideoMode(Game::Width, Game::Height), "SFML window");
	_player = new Player("res/xx_crusader_m.png");
	// if (!_socket.bind(4242))
	// {
	// 	std::cout << "bind not successful" << std::endl;
	// 	// return -1;
	// }

	std::string str = "test";
	char *test = pack(5, str.c_str(), 5);

	_socket.send(test, str.size() + 9 + 1, Game::Host, Game::Port);
}

Game::~Game (void) {}

char *			Game::pack(unsigned char id, char const * data, size_t length)
{
	size_t	size;
	char *	frame;

	size = sizeof(unsigned char) + sizeof(size_t) + sizeof(char) * (length);

	frame = static_cast<char *>(::operator new(size));

	memset(frame, 0, size);
	memcpy(frame, &id, sizeof(unsigned char));
	memcpy(frame + sizeof(unsigned char), &length, sizeof(size_t));

	if (length > 0)
		memcpy(frame + sizeof(unsigned char) + sizeof(size_t), data, length);

	return frame;
}

void	Game::update(void)
{
	sf::Event event;
	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window->close();
		if (event.type == sf::Event::KeyPressed)
			_player->update(event);
	}
}

void	Game::draw(void) const
{
	_window->clear();
	_player->draw(*_window, sf::RenderStates::Default);
	_window->display();
}

void	Game::run(void)
{
	while (_window->isOpen())
	{
		update();
		draw();
	}
}
