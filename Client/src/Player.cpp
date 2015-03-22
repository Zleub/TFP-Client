//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Player
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 22:30:49
// :ddddddddddhyyddddddddddd: Modified: 2015-03-22 22:08:46
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

Player::Player(std::string filename) : _orientation(2), _hscale(1)
{
	_texture = new sf::Texture();
	_texture->loadFromFile(filename);
	_sprite = new sf::Sprite(*_texture);
	_sprite->setTextureRect(sf::Rect<int>(48, 0, Player::Width, Player::Height));
	_sprite->setPosition(Game::Width / 2 - Player::Width / 2, Game::Height / 2 - Player::Height / 2);
}

void	Player::setTexture(void)
{
	_sprite->setScale(_hscale, 1);
	_sprite->setTextureRect(sf::Rect<int>(48 * _orientation, 0, Player::Width, Player::Height));
}

void	Player::KeyState(sf::Keyboard::Key k)
{
	enum Key
	{
		Up,
		Down,
		Left,
		Right
	};
	bool b[4];

	(void)k;
	b[Up] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	b[Down] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	b[Left] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	b[Right] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

	if (b[Right]) {
		_orientation = 2;
		_hscale = -1;
	}
	if (b[Down])
		_orientation = 0;
	if (b[Up])
		_orientation = 4;
	if (b[Left]) {
		_orientation = 2;
		_hscale = 1;
	}
	if (b[Left] && b[Down]) {
		_orientation = 1;
		_hscale = 1;
	}
	if (b[Left] && b[Up]) {
		_orientation = 3;
		_hscale = 1;
	}

	if (b[Right] && b[Down]) {
		_orientation = 1;
		_hscale = -1;
	}
	if (b[Right] && b[Up]) {
		_orientation = 3;
		_hscale = -1;
	}


	std::cout << b[0] << b[1] << b[2] << b[3] << std::endl;

	// if (k == sf::Keyboard::Up)
	// 	_orientation = 4;
	// else if (k == sf::Keyboard::Down)
	// 	_orientation = 0;
	// else if (k == sf::Keyboard::Left)
	// 	_orientation = 2;
	// if (sf::Keyboard::)
	this->setTexture();
}

void	Player::update(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
		this->KeyState(event.key.code);
	// _sprite->setTextureRect(sf::Rect<int>(48, 0, Player::Width, Player::Height));
}

void	Player::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(*_sprite, state);
}
