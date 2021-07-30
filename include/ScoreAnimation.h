#pragma once
#include "Board.h"
/// <summary>
/// after score goal celebration class
/// </summary>
class ScoreAnimation
{
public:
	ScoreAnimation();
	void Run(sf::RenderTarget& target);
	bool draw(sf::RenderTarget& target);

private:
	Sprite m_sprite;
};