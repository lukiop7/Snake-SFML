/**
* @file Apple.h
* @brief Object for eating class
* @author Pawel Szafraniec
*/

#pragma once
#include "Object.h"
#include <random>

/** @class Apple
*Apple Class handles functions for objects designed to be eaten by the snake.
*Public inheritance from Object class.
*/
class Apple :
	public Object
{
public:

	/**
	*Constructor
	*/
	Apple();

	/**
	*Destructor
	*/
	~Apple() {};

	/**
	*Updates state of the game.
	*/
	void update() override;

	/**
	*Draws sprite to the game window.
	*@param window render window.
	*/
	void draw(sf::RenderWindow& window) override;

	bool GetEaten() const; ///<getter
	void SetEaten(bool a); ////< setter
private:

	/**
	*Sets place for the apple inside the board.
	*/
	void position();
	bool _wasEaten;
};

