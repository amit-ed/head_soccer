#pragma once
#include ".//Moving_Objects/Players/Santa.h"
//----------------------------------------------------------------------------
bool Santa::m_registerit = Factory::registerit(santa, [](Vector2f loc, b2World* world, bool dir) ->
	std::unique_ptr<Object> { return std::make_unique<Santa>(loc, world,dir); });
//----------------------------------------------------------------------------
Santa::Santa(Vector2f loc, b2World* m_world, bool dir)
	: Player(loc, m_world, dir, Resources::instance().animationData(Resources::Santa)), m_yeti(make_unique<Yeti>(loc, m_world, dir))
{
	if (dir) m_key = Keyboard::X;
	else m_key = Keyboard::RShift;	//set yeti summon key
}
//----------------------------------------------------------------------------
//update the yeti and then do the usual player update
void Santa::update(sf::Time delta)
{
	m_yeti.get()->update();
	if (Keyboard::isKeyPressed(m_key))
	{
		m_yeti.get()->show();
	}
	Player::update(delta);
}