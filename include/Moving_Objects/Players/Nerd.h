#pragma once
#include "Player.h"
//player chracter
class Nerd : public Player
{
public:
	Nerd(Vector2f loc = { 0, 0 }, b2World* m_world = nullptr, bool p = false)
		: Player(loc, m_world, p, Resources::instance().animationData(Resources::Nerd))
	{}


private:
	static bool m_registerit;
};
bool Nerd::m_registerit = Factory::registerit(nerd, [](Vector2f loc, b2World* world, bool dir) ->
	std::unique_ptr<Object> { return std::make_unique<Nerd>(loc, world, dir); });