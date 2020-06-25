#include "Snake_Body.h"
#include "Game.h"

Snake_Body::Snake_Body(Snake_Body* prev) {
	load("images/body.png");
	GetSprite().setOrigin(sf::Vector2f(10, 10));
	if (prev == nullptr) {
		GetSprite().setPosition(sf::Vector2f(Game::SCREEN_WIDTH / 2+10, Game::SCREEN_HEIGHT / 2+10));
	}
	else {
		GetSprite().setPosition(prev->GetSprite().getPosition());
	}
}
void Snake_Body::draw(sf::RenderWindow& window) {
	Object::draw(window);
}

void Snake_Body::operator=(sf::Vector2f a)
{
	GetSprite().setPosition(a);
}

bool Snake_Body::operator==(Snake_Body* check)
{
	if (check == this) {
		return false;
	}
	else {
		if (GetSprite().getGlobalBounds().intersects(check->GetSprite().getGlobalBounds()))
			return true;
		else {
			return false;
		}
	}
}
