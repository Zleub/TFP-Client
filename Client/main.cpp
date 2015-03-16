#include <SFML/Graphics.hpp>
#include <iostream>

class Extern {
private:
	Extern(Extern const &);
	Extern &	operator=(Extern const &);
public:
	Extern(void);
	~Extern(void);
};

class Drawable {
private:
	Drawable(void);
	Drawable(Drawable const &);
	Drawable &	operator=(Drawable const &);

	sf::Texture		_texture;
	sf::Sprite		*_sprite;
public:
	Drawable(std::string);
	~Drawable(void);

	sf::Sprite & getSprite(void);
};

Drawable::Drawable(std::string filename)
{
	_texture.loadFromFile(filename);
	_sprite = new sf::Sprite(_texture);
}

sf::Sprite & Drawable::getSprite(void) { return *_sprite; }

class Interactible {
private:
	Interactible(Interactible const &);
	Interactible &	operator=(Interactible const &);
public:
	Interactible(void);
	~Interactible(void);
};

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
		_window->display();
	}
}

int main(void)
{
	Game	g;

	g.run();
}

// int main()
// {
// 	sf::Sprite sprite(texture);
// 	// Create a graphical text to display

// 	sf::Font font;
// 	if (!font.loadFromFile("ressources/arial.ttf"))
// 		return EXIT_FAILURE;
// 	sf::Text text("Hello SFML", font, 50);
// 	text.setPosition(100, 100);
// 	// Start the game loop
// 	while (window.isOpen())
// 	{
// 		// Process events
// 		sf::Event event;
// 		while (window.pollEvent(event))
// 		{
// 			// Close window: exit
// 			if (event.type == sf::Event::Closed)
// 				window.close();
// 		}
// 		// Clear screen
// 		window.clear();
// 		// Draw the sprite
// 		window.draw(sprite);
// 		// Draw the string
// 		window.draw(text);
// 		// Update the window
// 		window.display();
// 	}
// 	return EXIT_SUCCESS;
// }
