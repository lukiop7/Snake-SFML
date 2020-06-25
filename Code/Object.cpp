#include "Object.h"

Object::Object()
{
	_isLoaded = false;
}

Object::~Object()
{
}

void Object::update()
{
}

void Object::draw(sf::RenderWindow& window)
{
	if (_isLoaded) {
		window.draw(_sprite);
		return;
	}
	else {
		return;
	}
}

void Object::SetPosition(float x, float y)
{
	if (_isLoaded) {
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f Object::Getposition() const
{
	if (_isLoaded) {
		return _sprite.getPosition();
	}

	return sf::Vector2f();
}

sf::Sprite& Object::GetSprite()
{
		return _sprite;
}

void Object::load(std::string name)
{
	if (!_texture.loadFromFile(name)) {
		std::cout << "Error while loading " << name << std::endl;
		_isLoaded = false;
		return;
	}
	else {
		_sprite.setTexture(_texture);
		_isLoaded = true;
		return;
	}
}

