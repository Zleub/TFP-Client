//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Player
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 22:30:49
// :ddddddddddhyyddddddddddd: Modified: 2015-03-21 18:37:05
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Game.hpp>
#include <Player.hpp>

int	Player::Width = 48;
int	Player::Height = 80;

Player::Player(void) {}
Player::~Player(void) {}

Player::Player(std::string filename) : _orientation(2)
{
	_texture = new sf::Texture();
	_texture->loadFromFile(filename);
	_sprite = new sf::Sprite(*_texture);
	_sprite->setTextureRect(sf::Rect<int>(48, 0, Player::Width, Player::Height));
	_sprite->setPosition(Game::Width / 2 - Player::Width / 2, Game::Height / 2 - Player::Height / 2);
}

void	Player::update(void)
{
	_sprite->setTextureRect(sf::Rect<int>(48, 0, Player::Width, Player::Height));
}

void	Player::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(*_sprite, state);
}
