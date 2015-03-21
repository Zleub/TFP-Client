//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 23:44:55
// :ddddddddddhyyddddddddddd: Modified: 2015-03-21 00:21:47
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Game.hpp>

Game::Game (void)
{
	_window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");
	_player = new Player("ressources/xx_crusader_m.png");
}

Game::~Game (void) {}

void	Game::run(void) const
{
	while (_window->isOpen())
	{
		sf::Event event;
		while (_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window->close();
		}
		_window->clear();
		_player->draw(*_window, sf::RenderStates::Default);
		_window->display();
	}
}
