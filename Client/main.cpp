#include <SFML/Graphics.hpp>
#include <iostream>

class Drawable : public sf::Drawable {
private:
	Drawable(void);
	Drawable(Drawable const &);
	Drawable &	operator=(Drawable const &);

	sf::Texture		_texture;
	sf::Sprite		*_sprite;
	virtual void 	draw(sf::RenderTarget&, sf::RenderStates) const;
public:
	Drawable(std::string);
	~Drawable(void);

	sf::Sprite &	getSprite(void);
};

Drawable::Drawable(std::string filename) : sf::Drawable()
{
	_texture.loadFromFile(filename);
	_sprite = new sf::Sprite(_texture);
}

Drawable::~Drawable(void) {};

// void		Drawable::draw(sf::RenderWindow w) { w.draw(_sprite); }
void Drawable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	(void)states;
	target.draw(*_sprite);
}

sf::Sprite & Drawable::getSprite(void) { return *_sprite; }

class Game {
private:
	Game(Game const &);
	Game &	operator=(Game const &);

	sf::RenderWindow	*_window;
	Drawable			*_drawable;
public:
	Game(void);
	~Game(void);

	void	run(void);
};

Game::Game(void)
{
	this->_window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");
	this->_drawable = new Drawable("ressources/xx_crusader_m.png");
}

Game::~Game(void) {}

void	Game::run(void)
{
	sf::Font f;
	f.loadFromFile("ressources/arial.ttf");

	sf::Text t("CACA", f, 20);

	while (_window->isOpen())
	{
		sf::Event event;
		while (_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window->close();
		}
		_window->clear();
		_window->draw(_drawable->getSprite());
		sf::Vector2i position = sf::Mouse::getPosition(*_window);
		t.setPosition(position.x, position.y);
		// t.draw(_window);
		_window->draw(t);
		_window->display();
	}
}

int main(void)
{
	Game	g;

	g.run();
}
