//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Player
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 22:30:49
// :ddddddddddhyyddddddddddd: Modified: 2015-03-21 13:14:49
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Player.hpp>

Player::Player(void) {}
Player::~Player(void) {}

Player::Player(std::string filename) : _orientation(2)
{
	_texture = new sf::Texture();
	_texture->loadFromFile(filename);
	_sprite = new sf::Sprite(*_texture);
	_sprite->setTextureRect(sf::Rect<int>(48, 0, 48, 80));
	_sprite->setPosition(100, 100);
}

void	Player::update(void)
{
	_sprite->setTextureRect(sf::Rect<int>(48, 0, 48, 80));
}

void	Player::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(*_sprite, state);
}
