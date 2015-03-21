//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Player
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 22:28:10
// :ddddddddddhyyddddddddddd: Modified: 2015-03-21 00:28:38
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable {
private:
	Player(Player const &);
	Player &	operator=(Player const &);

	sf::Texture		*_texture;
	sf::Sprite		*_sprite;
public:
	Player(void);
	Player(std::string);
	~Player(void);

	virtual void 	draw (sf::RenderTarget &, sf::RenderStates) const;
};

#endif
