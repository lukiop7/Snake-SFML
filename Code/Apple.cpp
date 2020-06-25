#include "Apple.h"

Apple::Apple()
{
	load("images/apple.png");
	GetSprite().setOrigin(10,10);
	position();
		_wasEaten = false;
}

void Apple::update()
{
	if (_wasEaten == true) {
		position();
		_wasEaten = false;
	}
}

void Apple::draw(sf::RenderWindow& window)
{
	Object::draw(window);
}

bool Apple::GetEaten() const
{
	return _wasEaten;
}

void Apple::SetEaten(bool a)
{
	_wasEaten = a;
}

void Apple::position()
{
	int x, y;
	bool correct = false;
	while (!correct) {
		std::random_device rd;
		std::mt19937 rand(rd());
		std::uniform_int_distribution<> pos(20, 620);

		x = pos(rd);
		std::uniform_int_distribution<> pos1(20, 460);
		y = pos1(rd);
		if (x % 10 == 0 && x % 20 != 0 && y % 10 == 0 && y % 20 != 0)
			correct = true;
	}
	GetSprite().setPosition(sf::Vector2f(x, y));
}
