#pragma once
#include "ScoreBoard.h"
#include "macros.h"

#include "../include/All_animation/Textures.h"
//----------------------------------------------------------------------------
//the text that say "PlayerX score:"
ScoreBoard::ScoreBoard(float loc,bool player_number)
{
	if (player_number) { m_text.setPosition(loc-160.f, 10);; m_player_number = 1; }
	else {m_text.setPosition(loc-90.f, 10); m_player_number = 2;}
	m_text.setFont(Textures::instance().get_Font());
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(24);
	m_text.setString("Player " + to_string(m_player_number)+ " Score: "  + to_string(m_score));
}
//----------------------------------------------------------------------------
void ScoreBoard::add()
{
	m_score++;
	m_text.setString("Player " + to_string(m_player_number) + " Score: " + to_string(m_score));
}
//----------------------------------------------------------------------------
void ScoreBoard::draw(sf::RenderTarget& target) const
{
	target.draw(m_text);
}
//----------------------------------------------------------------------------