#include "intro.h"

intro::intro(): _isLoaded(false)
{
	if (!_texture.loadFromFile("images/intro.png")) {
		std::cout << "Error, cannot load file: intro.png " << std::endl;
	}
	else {
		_sprite.setTexture(_texture);
		_isLoaded = true;
	}
}

intro::~intro()
{
}

void intro::show(sf::RenderWindow& window)
{
	if (_isLoaded) {
		window.draw(_sprite);
		window.display();
	}
}
