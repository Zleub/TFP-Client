//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 23:42:51
// :ddddddddddhyyddddddddddd: Modified: 2015-03-21 18:44:00
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Player.hpp>

class Game {
private:
	Game(Game const &);
	Game &	operator=(Game const &);

	Player				*_player;
	sf::RenderWindow	*_window;
public:
	Game(void);
	~Game(void);

	static int Width;
	static int Height;

	void	update(void) ;
	void	draw(void) const ;
	void	run(void) ;
};

#endif
