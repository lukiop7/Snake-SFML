/**
* @file HUD.h
* @brief HUD class.
* @author Pawel Szafraniec
*/
#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Snake.h"

/** @class HUD
* Displays score.
*/
class HUD
{
public:
	/**
	*Constructor
	*/
	HUD();

	/**
	*Destructor
	*/
	~HUD();

	/**
	*Overloaded operator. Sets pointer to Snake
	*@param player pointer to the Snake
	*/
	void operator=(Snake* player);

	/**
	*Shows score on the screen
	*@param window render 
	*/
	void showScore(sf::RenderWindow& window);
private:
	sf::Font font;
	sf::Text text;
	sf::Text textBest;
	Snake* _player;///<_player pointer to the Snake object.6
	int best;///<best score-also displayed on the screen
};

