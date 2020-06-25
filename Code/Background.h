/**
* @file Background.h
* @brief Rendered window class
* @author Pawel Szafraniec
*/
#pragma once
#include "Object.h"

/** @class background
* Class shows game screen
* Public inheritance from Object class
*/
class Background :
	public Object 
{
public:
	/** 
	*Constructor
	*/
	Background();

	/**
	*Destructor
	*/
	~Background();

	/**
	*Draws sprite to the render window.
	*@param window render window.
	*/
	void draw(sf::RenderWindow& window) override;

};

