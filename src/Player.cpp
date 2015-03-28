//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  TFP:Player
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-03-20 22:30:49
// :ddddddddddhyyddddddddddd: Modified: 2015-03-26 10:13:24
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Player.hpp>
#include <Client.hpp>

int	Player::Width = 48;
int	Player::Height = 80;

Player::Player(void) {}
Player::~Player(void) {}

Player::Player(std::string filename) : _orientation(0), _hscale(1)
{
	_texture = new sf::Texture();
	_texture->loadFromFile(filename);
	_sprite = new sf::Sprite(*_texture);
	_sprite->setTextureRect(sf::Rect<int>(0, 0, Player::Width, Player::Height));
	_sprite->setPosition(Game::Width / 2, Game::Height / 2);
	_sprite->setOrigin(Player::Width / 2, Player::Height / 2);
}

void	Player::setTexture(void)
{
	_sprite->setTextureRect(sf::Rect<int>(48 * _orientation, 0, Player::Width, Player::Height));
	_sprite->setScale(_hscale, 1);
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

	if (Client::Verb)
	std::cout << "Movement Matrix: " << b[0] << b[1] << b[2] << b[3] << std::endl;

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
