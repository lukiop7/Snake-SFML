/**
* @file Snake_Body.h
* @brief file handling body of the snake.
* @author Pawel Szafraniec
*/
#pragma once
#include "Object.h"

/** @class Snake_Body
* Handles body elements of the snake.
* Public inheritance from Object class.
*/
class Snake_Body :
	public Object
{
public:
	/**
	*Constructor 
	*@param pointer to the Snake_Body object.
	*/
	Snake_Body(Snake_Body* prev);

	/**
	*Destructor.
	*/
	~Snake_Body() {};

	/**
	*Draws sprite to the game window.
	*@param window render window.
	*/
	void draw(sf::RenderWindow& window);

	/**
	*Overloaded = operator.
	*Sets position of the snake.
	*@param vector for storing position coordinates.
	*
	*/
	void operator =(sf::Vector2f a);

	/**
	*Overloaded == operator.
	*compares positions and checks their equality
	*@param check pointer to the Snake_Body object
	*@return true if yes otherwise false.
	*/
	bool operator ==(Snake_Body* check); 
};

