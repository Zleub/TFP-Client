//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Player
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 22:28:10
// :ddddddddddhyyddddddddddd: Modified: 2015-03-25 17:59:40
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
	Player(void);
	Player(Player const &);
	Player &	operator=(Player const &);

	static int		Width;
	static int		Height;

	int				_orientation;
	int				_hscale;
	sf::Texture		*_texture;
	sf::Sprite		*_sprite;

	void			KeyState(sf::Keyboard::Key);
public:
	Player(std::string);
	~Player(void);

	void			update(sf::Event);
	virtual void	draw(sf::RenderTarget &, sf::RenderStates) const ;

	void			setTexture(void);
};

#endif
