//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Player
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 22:30:49
// :ddddddddddhyyddddddddddd: Modified: 2015-03-21 00:59:18
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Player.hpp>

Player::Player(void) {}
Player::~Player(void) {}

Player::Player(std::string filename)
{
	_texture = new sf::Texture();
	_texture->loadFromFile(filename);
	_sprite = new sf::Sprite(*_texture);
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(*_sprite, state);
}
