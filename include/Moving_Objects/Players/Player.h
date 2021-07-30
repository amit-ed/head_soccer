#pragma once
#include "../include/Moving_Objects/MovingObject.h"
#include "../include/Static_Objects/Foot.h"
#include "ScoreBoard.h"
//player class control all the players
class Player : public MovingObject
{
public:
    Player(Vector2f loc = { 0, 0 }, b2World * m_world = nullptr, bool p = false, const AnimationData& data = Resources::instance().animationData(Resources::Player));
    template <auto up, auto left, auto right, auto kick>
	void make_keys();
    void update(sf::Time delta);
	void collide();
	void kick();
	void add_score();//if goal scored add score
	virtual bool jump_validation();
	void draw(sf::RenderTarget& target) const { target.draw(m_sprite); m_foot->draw(target); m_score->draw(target); }
	Foot* get_foot() { return m_foot.get(); }
	const int return_score()const { return m_score->return_score(); }
	//======================================================================
protected:
    void update_picture(sf::Time delta);
	map<Keyboard::Key, Direction> m_keyToVectorMapping;
	Keyboard::Key m_kick;
	float m_startingY = 0;
	bool m_collide = false;
	unique_ptr<Foot> m_foot;//pointer to player foot
	unique_ptr<ScoreBoard> m_score;//pointer to player score
};

//========================================================================
//template function to use same class for both players
template <auto up, auto left, auto right, auto kick>
void Player::make_keys()
{
	m_keyToVectorMapping = 
	{
		{ up , Direction::Up },
		{ right , Direction::Right },
		{ left ,Direction::Left },
	};
	m_kick = kick;
}