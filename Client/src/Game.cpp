//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 23:44:55
// :ddddddddddhyyddddddddddd: Modified: 2015-03-21 13:22:14
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Game.hpp>

Game::Game (void)
{
	_window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");
	_player = new Player("res/xx_crusader_m.png");
}

Game::~Game (void) {}

void	Game::update(void)
{
	_player->update();
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
		sf::Event event;
		while (_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window->close();
		}
		update();
		draw();
	}
}
