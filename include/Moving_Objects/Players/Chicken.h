#pragma once
#include "Player.h"
// chicken character
class Chicken : public Player
{
public:
	Chicken(Vector2f loc = { 0, 0 }, b2World* m_world = nullptr, bool p = false)
		: Player(loc, m_world, p, Resources::instance().animationData(Resources::Chicken))
	{};
	bool jump_validation() { return false; };
	float double_jump() { return toVector(m_dir).y; };

private:
	static bool m_registerit;
};
bool Chicken::m_registerit = Factory::registerit(chicken, [](Vector2f loc, b2World* world, bool dir) ->
	std::unique_ptr<Object> { return std::make_unique<Chicken>(loc, world, dir); });