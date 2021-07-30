#pragma once
#include "StaticObject.h"
//each player has foot 
class Foot : public StaticObject
{
public: 
	Foot(Vector2f loc = { 0, 0 }, b2World* m_world = nullptr, bool Dir = false);
	void draw(sf::RenderTarget& target) const { if (m_show) target.draw(m_sprite); }
	void show() { m_show = true;  m_clock.restart();};//when user pressing kick buttom
	void hide() { m_show = false; m_sprite.setPosition(0, 0); };
	void update(Vector2f loc) { if(m_show)m_sprite.setPosition(loc); if (m_show && m_clock.getElapsedTime() > sf::seconds(1.5f)) hide(); }
	void scale(bool dir = true) {
		m_dir = dir;
		if (dir)
			m_sprite.setScale(-1, 1);
		if (!dir)
			m_sprite.setScale(1, 1);
	}
	bool get_dir() { return m_dir; }
private:
	bool m_dir = false;
	bool m_show = false;
	Clock m_clock;
};