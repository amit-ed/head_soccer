#pragma once
#include "ScoreAnimation.h"
//----------------------------------------------------------------------------
//the goal animation after someone scored a goal
ScoreAnimation::ScoreAnimation()
{
	m_sprite.setTexture(Textures::instance().get_Textures(GOAL_CELEBRATION));
	m_sprite.setPosition(Vector2f(0, 100));
}
//----------------------------------------------------------------------------
bool ScoreAnimation::draw(sf::RenderTarget& target)
{
	target.draw(m_sprite);
	m_sprite.move(1, 0);	//every round move it a little
	if (m_sprite.getPosition().x >= 450) { 
		m_sprite.setPosition(Vector2f(0, 100));
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------