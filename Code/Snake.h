/**
* @file Snake.h
* @brief Snake class file
* @author Pawel Szafranie
*/
#pragma once
#include "Object.h"
#include <vector>
#include "Apple.h"
#include "Snake_Body.h"
#include "Game.h"
#include <iostream>
#include <algorithm>

class Snake :
	public Object
{
public:
	/**
	*One argument constructor.
	*@param apple pointer to the Apple.
	*/
	Snake(Apple* apple);

	/**
	*Destructor where the functor is used.
	*/
	~Snake();

	/**
	*Updates state of the game.
	*/
	void update() override;

	/**
	*Draws sprite to the game window.
	*@param window render window.
	*/
	void draw(sf::RenderWindow& window) override;

	/**
	*Gets score of the game.
	*/
	int GetScore() const; 
private:
	/**
	*Reads input and changes direction of the object.
	*/
	void input();

	/**
	*Checks collision of the snake with the wall.
	*/
	void bounds();

	/**
	*Checks whether snake ate the apple. If yes, increases its length.
	*/
	void apple();

	/**
	*Resets snake to the begginging state.
	*/
	void reset();

	/**
	*Checks collision of the snake with himself.
	*/
	void collision();

	/**
	*Depending on current snake direction, moves him in a proper way
	*/
	void positions();
	int score;///<score
	int delay; ///<necessary delay on the start and on the reset states
	double velocity; ///< movement speed
	std::vector<Snake_Body*> _body; ///<vector contains pointers on objects from which snake is builded

	Apple* _apple; ///<Apple pointer
	enum dir { left, right, up, down }; ///<enum determines direction of movement
	dir _dir; ///<object for using above enumerator

	/**
	*Struct for functor for deallocating elements
	*/
	struct Destroy { 
		/**
		*Overloaded function operator 
		*/
		void operator()(const Snake_Body* a)const { 
			delete a;
		}
	};
};

