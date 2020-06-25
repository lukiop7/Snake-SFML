#include "Snake.h"


Snake::Snake(Apple* apple): score(0),_apple(apple),velocity(20.0), delay(0)
{
	_body.push_back(new Snake_Body(nullptr));
	_dir = Snake::up;
	for (int i = 0; i < 2; i++) {
		_body.push_back(new Snake_Body(_body[i]));
		_body[i + 1]->GetSprite().setPosition(sf::Vector2f(_body[i]->GetSprite().getPosition().x, _body[i]->GetSprite().getPosition().y+20));
	}
}

Snake::~Snake()
{
	std::for_each(_body.begin(), _body.end(), Destroy());
	_body.clear();
}

void Snake::update()
{
	if (delay != 15)
		delay += 1;
	else {
		input();
		bounds();
		positions();
		apple();
		collision();
	}
}

void Snake::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < _body.size(); i++) {
		_body[i]->draw(window);
	}
}

int Snake::GetScore() const
{
	return score;
}

void Snake::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (_dir != Snake::right)
			_dir = Snake::left;
		else
			return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (_dir != Snake::left)
			_dir = Snake::right;
		else
			return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (_dir != Snake::down)
			_dir = Snake::up;
		else
			return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (_dir != Snake::up)
			_dir = Snake::down;
		else
			_dir = Snake::up;
	}
}

void Snake::bounds()
{
	if (_body[0]->GetSprite().getPosition().x >= 620) 
		reset();
	
	if (_body[0]->GetSprite().getPosition().y >= 460) 
		reset();
	
	if (_body[0]->GetSprite().getPosition().x <= 20) 
		reset();
	
	if (_body[0]->GetSprite().getPosition().y <= 20) 
		reset();
	
}

void Snake::apple()
{
	if (_body[0]->GetSprite().getGlobalBounds().intersects(_apple->GetSprite().getGlobalBounds())) {
		_apple->SetEaten(true);
		_body.push_back(new Snake_Body(_body.back()));
		_body.back()->GetSprite().setPosition(sf::Vector2f(_body[_body.size() - 2]->GetSprite().getPosition().x, _body[_body.size() - 2]->GetSprite().getPosition().y + 21));
		score += 1;
	}
}

void Snake::reset()
{
	std::vector<Snake_Body*>::iterator vecIter;
	for (vecIter = _body.begin(); vecIter != _body.end(); vecIter++)
		delete* vecIter;
	_body.clear();
	_body.push_back(new Snake_Body(nullptr));
	_dir = Snake::up;
	for (int i = 0; i < 2; i++) {
		_body.push_back(new Snake_Body(_body[i]));
		_body[i + 1]->GetSprite().setPosition(sf::Vector2f(_body[i]->GetSprite().getPosition().x, _body[i]->GetSprite().getPosition().y + 21));
	}
	score = 0;
	delay = 0;
}

void Snake::collision()
{
	for (int i = 1; i < _body.size(); i++) {
		if (*_body[0] == _body[i]) {
			reset();
		}
	}
}

void Snake::positions(){
	switch (_dir) {
	case left:
	{
		sf::Vector2f temp(_body[0]->GetSprite().getPosition());
		for (int i = 1; i < _body.size(); i++) {
			sf::Vector2f temp1 = _body[i]->GetSprite().getPosition();
			*_body[i] = temp;
			temp = temp1;
			
		}
		_body[0]->GetSprite().setPosition(sf::Vector2f(_body[0]->GetSprite().getPosition().x - velocity, _body[0]->GetSprite().getPosition().y));
		
		break;
	}
	case right:
	{
		
		sf::Vector2f temp(_body[0]->GetSprite().getPosition());
		for (int i = 1; i < _body.size(); i++) {
			sf::Vector2f temp1 = _body[i]->GetSprite().getPosition();
			*_body[i] = temp;
			temp = temp1;
		}
		_body[0]->GetSprite().setPosition(sf::Vector2f(_body[0]->GetSprite().getPosition().x + velocity, _body[0]->GetSprite().getPosition().y));
		break;
	}
	case up:
	{
		sf::Vector2f temp(_body[0]->GetSprite().getPosition());
		for (int i = 1; i < _body.size(); i++) {
			sf::Vector2f temp1 = _body[i]->GetSprite().getPosition();
			*_body[i] = temp;
			temp = temp1;
		}
		_body[0]->GetSprite().setPosition(sf::Vector2f(_body[0]->GetSprite().getPosition().x, _body[0]->GetSprite().getPosition().y - velocity));
		break;
	}
	case down:
	{
		sf::Vector2f temp(_body[0]->GetSprite().getPosition());
		for (int i = 1; i < _body.size(); i++) {
			sf::Vector2f temp1 = _body[i]->GetSprite().getPosition();
			*_body[i] = temp;
			temp = temp1;
		}
		_body[0]->GetSprite().setPosition(sf::Vector2f(_body[0]->GetSprite().getPosition().x, _body[0]->GetSprite().getPosition().y + velocity));
		break;
	}
	}
}
