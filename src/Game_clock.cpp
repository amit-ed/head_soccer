#pragma once
#include "Game_clock.h"
#include <sstream>
//----------------------------------------------------------------------------
Game_clock::Game_clock()
{
	//setting text properties
	m_text.setPosition(350, 10);
	m_text.setFont(Textures::instance().get_Font());
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(24);
}
//----------------------------------------------------------------------------
bool Game_clock::update_time()
{	//setting the text on screen to be easy to read timer base on m_clock
	sf::Time elapsed = m_clock.getElapsedTime();
	std::stringstream time;
	int time_left = (Game_time - (int)elapsed.asSeconds()) + m_counter.asSeconds();	//add the pause time
	int min_left = int(time_left / 60);
	int sec_left = (time_left - min_left * 60);
	if (sec_left < 10)
		time << "Time left   "
		<< std::to_string(min_left) << ":0" << std::to_string(sec_left);
	else
		time << "Time left   "
		<< std::to_string(min_left) << ":" << std::to_string(sec_left);
	m_text.setString(time.str());
	if (time_left > 0)
		return true;

	return false;
}

//----------------------------------------------------------------------------
//just draw the text
void Game_clock::draw(sf::RenderTarget& target) const
{
	target.draw(m_text);
}