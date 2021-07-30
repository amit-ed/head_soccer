#pragma once
#include <SFML/Graphics.hpp>
#include "../include/All_animation/Textures.h"
using namespace std;
using namespace sf;

class Game_clock
{
public:
	Game_clock();
	bool update_time();//bool function to know if game time ended
	void draw(sf::RenderTarget& target) const;
	void start_clock() { m_clock.restart(); m_counter = seconds(0.f);}
	void pause() { m_clock2.restart(); }//pause game clock if game pressed pause
	void start() { m_counter += m_clock2.getElapsedTime(); }//after pause adding the pause time to game clock
private:
	Time m_counter = seconds(0.f);
	Text m_text;
	Clock m_clock = Clock(), m_clock2 = Clock();
};