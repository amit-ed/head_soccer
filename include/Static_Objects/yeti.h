#pragma once
#include "../Static_Objects/StaticObject.h"
//only santa has poiter to yeti,Special power of santa
class Yeti : public StaticObject
{
public:
	Yeti(Vector2f loc = { 0, 0 }, b2World* m_world = nullptr, bool Dir = false);
	void draw(sf::RenderTarget& target) const { if (m_show) target.draw(m_sprite); }
	void show() { m_show = true; m_clock.restart(); m_body->GetFixtureList()->SetSensor(false); };
	void hide() { m_show = false; m_body->GetFixtureList()->SetSensor(true); };
	void update() { if (m_show && m_clock.getElapsedTime() > sf::seconds(1.5f)) hide(); }
	
private:
	bool m_show = false;
	Clock m_clock;
};