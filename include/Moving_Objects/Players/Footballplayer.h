#pragma once
#include "Player.h"

class Footballplayer : public Player
{
public:
	Footballplayer(Vector2f loc = { 0, 0 }, b2World* m_world = nullptr, bool p = false)
		: Player(loc, m_world, p, Resources::instance().animationData(Resources::Player)) 
	{
		m_speed = 1.5;//to make him faster
	}


private:
	static bool m_registerit;
};

bool Footballplayer::m_registerit = Factory::registerit(football_player, [](Vector2f loc, b2World* world, bool dir) ->
	std::unique_ptr<Object> { return std::make_unique<Footballplayer>(loc, world, dir); });