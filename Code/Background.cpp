#include "Background.h"

Background::Background()
{
	load("images/back.png");
}

Background::~Background()
{

}

void Background::draw(sf::RenderWindow& window)
{
	Object::draw(window);
}
