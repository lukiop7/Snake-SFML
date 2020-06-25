/**
* @file intro.h
* @brief intro handling file.
* @author Pawel Szafraniec
*/
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
/** @class intro
* Class showing intro and pause screen.
*/
class intro
{
public:

	/**
	*Constructor.
	*/
	intro();

	/**
	*Destructor.
	*/
	~intro();

	/**
	*Draws sprite to the game window.
	*@param window render window.
	*/
	void show(sf::RenderWindow& window);
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	bool _isLoaded;
};

