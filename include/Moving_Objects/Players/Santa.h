#pragma once
#include "Player.h"
#include "../include/Static_Objects/yeti.h"
//player character
class Santa : public Player
{
public:
	Santa(Vector2f loc = { 0, 0 }, b2World* m_world = nullptr, bool p = false);
	void update(sf::Time delta) override;
	void draw(sf::RenderTarget& target) const { Player::draw(target); m_yeti.get()->draw(target); }
	Yeti* get_yeti() { return m_yeti.get(); }

private:
	unique_ptr<Yeti> m_yeti;
	Keyboard::Key m_key;
	static bool m_registerit;
};