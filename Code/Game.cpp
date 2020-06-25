#include "Game.h"
#include <iostream>

void Game::initialize()
{
	if (_state != Game::start)
		return;
	else {
		_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Ssssnake");
		_mainWindow.setFramerateLimit(15);
		_apple = new Apple();
		_player = new Snake(_apple);
		_hud=_player;
		_state = Game::showintro;

		while (_state != Game::exit)
			loop();

		_mainWindow.close();
		delete _player;
		delete _apple;
	}
}

void Game::loop()
{
	sf::Event event;
	if (_state == Game::showintro) {
		_intro.show(_mainWindow);
		_mainWindow.pollEvent(event);
		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Enter)
				_state = Game::play;
		if (event.type == sf::Event::Closed)
			_state = Game::exit;
	}
	if (_state == Game::play) {
		_mainWindow.pollEvent(event);
		if (event.type == sf::Event::Closed)
			_state = Game::exit;
		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Escape)
				_state = Game::showintro;

			_mainWindow.clear(sf::Color::Black);
			_player->update();
			_apple->update();
			_back.draw(_mainWindow);
			_player->draw(_mainWindow);
			_apple->draw(_mainWindow);
			_hud.showScore(_mainWindow);
			_mainWindow.display();
		
	}
}



Game::State Game::_state=start;
sf::RenderWindow Game::_mainWindow;
Snake* Game::_player;
Apple* Game::_apple;
Background Game::_back;
HUD Game::_hud;
intro Game::_intro;