/**
* @file Game.h
* @brief Game class
* @author Pawel Szafraniec
*/
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Object.h"
#include "Apple.h"
#include "Snake.h"
#include "Background.h"
#include "HUD.h"
#include "intro.h"
/** @class Game
* Most important functions for the game are handled by this class-initialization, game loop, status of the game.
*/
class Game
{

public:
	const static int SCREEN_WIDTH = 640; ///<game screen width.
	const static int SCREEN_HEIGHT = 480; ///<game screen height.

	/**
	*Initializing game objects.
	*/
	static void initialize();
private:

	/**
	*Game loop which calls functions depending on current game state.
	*/
	static void loop();

	/**
	*Enumerator representing game states.
	*/
	enum  State {
		start,play,exit,showintro
	};

	static State _state;
	static sf::RenderWindow _mainWindow;///<rendering game window.
	static Snake* _player;
	static Apple* _apple;
	static Background _back;
	static HUD _hud;
	static intro _intro;

};

