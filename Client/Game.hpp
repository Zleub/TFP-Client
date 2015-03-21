//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 23:42:51
// :ddddddddddhyyddddddddddd: Modified: 2015-03-21 00:20:21
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GAME_HPP
#define GAME_HPP

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

	void run(void) const ;
};

#endif
