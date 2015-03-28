//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Game
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 23:42:51
// :ddddddddddhyyddddddddddd: Modified: 2015-03-26 11:18:20
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GAME_HPP
#define GAME_HPP

// #include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <Player.hpp>

class Game {
private:
	Game(Game const &);
	Game &	operator=(Game const &);

	Player					*_player;
	sf::RenderWindow		*_window;

	sf::UdpSocket			_socket;
public:
	Game(void);
	~Game(void);

	/** \brief Window Width
	*
	*	defined in game.conf.lua */
	static int				Width;
	/** \brief Window Height
	*
	*	defined in game.conf.lua */
	static int				Height;
	/** \brief Socket Handling
	*
	*	defined in game.conf.lua */
	static std::string		Host;
	/** \brief Socket Handling
	*
	*	defined in game.conf.lua */
	static int				Port;

	/** \brief Main update function */
	void					update(void) ;
	/** \brief Main draw function */
	void					draw(void) const ;
	/** \brief Main loop function */
	void					run(void) ;

	char *					pack(unsigned char, char const *, size_t);
};

#endif
