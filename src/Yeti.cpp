#pragma once
#include ".//Static_Objects/yeti.h"

Yeti::Yeti(Vector2f loc, b2World* m_world, bool Dir)
: StaticObject(Vector2f(loc.x, loc.y + Extra + 15), m_world, &Textures::instance().get_Textures(YETI_TEX))
{	
	if (!Dir) flip();	

	//we need the yeti to be part of the physics for it to stop and collide with the ball
	b2PolygonShape rec;
	rec.SetAsBox(m_sprite.getTexture()->getSize().x / 2 - 2.f, m_sprite.getTexture()->getSize().y / 2.7);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &rec;
	m_fixture = m_body->CreateFixture(&fixtureDef);
	m_body->GetFixtureList()->SetSensor(true);
}