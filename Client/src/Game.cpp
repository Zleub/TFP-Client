//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 23:44:55
// :ddddddddddhyyddddddddddd: Modified: 2015-03-22 21:31:50
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Game.hpp>

int	Game::Width = 800;
int	Game::Height = 600;

Game::Game (void)
{
	_window = new sf::RenderWindow(sf::VideoMode(Game::Width, Game::Height), "SFML window");
	_player = new Player("res/xx_crusader_m.png");
}

Game::~Game (void) {}

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
