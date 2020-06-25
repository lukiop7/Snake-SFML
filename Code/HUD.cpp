#include "HUD.h"
HUD::HUD()
{
	best = 0;
	_player = nullptr;
	font.loadFromFile("comic.ttf");
	text.setFont(font);
	textBest.setFont(font);
	textBest.setCharacterSize(20);
	textBest.setFillColor(sf::Color::White);
	textBest.setPosition(540, 0);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	text.setPosition(20, 0);

}

HUD::~HUD()
{
}


void HUD::operator=(Snake* player)
{
	_player = player;
}

void HUD::showScore(sf::RenderWindow& window)
{
	text.setString("SCORE: " + std::to_string(_player->GetScore()));
	textBest.setString("BEST: " + std::to_string(best));
	if(_player->GetScore()>best)
	best = _player->GetScore();
	window.draw(text);
	window.draw(textBest);
}