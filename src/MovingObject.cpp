#pragma once
#include "../include/Moving_Objects/MovingObject.h"
//----------------------------------------------------------------------------
MovingObject::MovingObject(Vector2f loc , b2World* m_world , const AnimationData& data )
	: Object(loc), m_animation(Animation(data, Direction::Right, m_sprite))
{
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2));
	//----------------physics-------------------------------
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(m_sprite.getPosition().x, Board_Height - m_sprite.getPosition().y);
	m_body = m_world->CreateBody(&bodyDef);
	m_body->SetFixedRotation(true);
	//----------------physics-------------------------------
};
//----------------------------------------------------------------------------
//moves the object (his physics body) to the direction he is set to (his m_dir)
void MovingObject::step_to_dir()
{
	b2Vec2 vel = m_body->GetLinearVelocity();
	float desiredVel = 0;

	if (m_dir == Direction::Up)
	{
		float velChange = double_jump() - vel.y;
		float impulse = m_body->GetMass() * velChange;
		m_body->ApplyLinearImpulse(b2Vec2(0, impulse), m_body->GetWorldCenter(), true);
	}
	else {
		float velChange = (toVector(m_dir).x * m_speed) - vel.x;
		float impulse = m_body->GetMass() * velChange;
		m_body->ApplyLinearImpulse(b2Vec2(impulse, 0), m_body->GetWorldCenter(), true);
	}
		//follow the physics body with the object's sprite
	m_sprite.setPosition(m_body->GetPosition().x, Board_Height - m_body->GetPosition().y);
}
//----------------------------------------------------------------------------