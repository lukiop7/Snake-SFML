/**
* @file Object.h
* @brief Object class
* @author Pawel Szafraniec
*/
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>

/** @class Object
* Abstract class for objects displayed on the screen. 
* Handles loading images, updates and sets position of the object.
*/
class Object
{
public:

	/**
	*Constructor.
	*/
	Object();

	/**
	*Virtual destructor.
	*/
	virtual ~Object();

	/**
	*Calls update function
	*/
	virtual void update();

	/**
	* Draws sprite to the game window.
	* @param window render window.
	*/
	virtual void draw(sf::RenderWindow& window);


	virtual void SetPosition(float x, float y);
	virtual sf::Vector2f Getposition() const;
	sf::Sprite& GetSprite();
protected:
	/**
	*Loading texture from the file.
	*@param string filename
	*/
	void load(std::string name);
private:
	bool _isLoaded;
	sf::Sprite _sprite;
	sf::Texture _texture;
};

