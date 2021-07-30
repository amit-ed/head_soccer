#pragma once
#include "../include/Moving_Objects/Ball.h"
const auto timer = sf::seconds(0.16666f);
//----------------------------------------------------------------------------
bool Ball::m_registerit = Factory::registerit(ball, [](Vector2f loc, b2World* world, bool dir) ->
    std::unique_ptr<Object> { return std::make_unique<Ball>(loc, world); });
            //register for the factory
//----------------------------------------------------------------------------
Ball::Ball(Vector2f loc, b2World* m_world)
    : MovingObject(loc,  m_world,  Resources::instance().animationData(Resources::Ball))
{
    m_dir = Direction::Up;

    b2CircleShape dynamicBall;
    dynamicBall.m_radius = m_sprite.getGlobalBounds().height *0.4;
    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.restitution = 0.8f;
    fixtureDef.shape = &dynamicBall;
    fixtureDef.density = 1.f;
    fixtureDef.friction = 0.0008f;
    m_fixture = m_body->CreateFixture(&fixtureDef);
    
    //--------------------------------------ball------------------------------
    m_body->ApplyForce(b2Vec2(0, 3500000), b2Vec2(m_sprite.getPosition().x, Board_Height - m_sprite.getPosition().y), true);

    //=========================================================================
    my_sound.setBuffer(Sounds_E::instance().get_Sounds(1));
    my_sound.setVolume(50);
}
//----------------------------------------------------------------------------
void Ball::update(sf::Time delta)
{
    if (m_scored) return;
    Vector2f position = (m_sprite.getPosition());
    
    m_sprite.setPosition(m_body->GetPosition().x, Board_Height - m_body->GetPosition().y);
    m_sprite.setRotation(m_body->GetAngle());
    if (position == m_sprite.getPosition()) {
        m_animation.direction(Direction::Stay);
        m_dir = Direction::Stay;
    }
    if (position.x > m_sprite.getPosition().x) {
        m_animation.direction(Direction::Left);
        m_dir = Direction::Left;
    }
    if (position.x < m_sprite.getPosition().x) {
        m_animation.direction(Direction::Right);
        m_dir = Direction::Right;
    }
    m_animation.update(delta);
};
//----------------------------------------------------------------------------
void Ball::kick_me(bool dir)
{
    b2Vec2 vel = m_body->GetLinearVelocity();
    float desiredVel = 0;
    float velChange = double_jump() - vel.x;
    float impulse = m_body->GetMass() * velChange;
    if (dir )
    {
        m_body->ApplyLinearImpulse(b2Vec2(impulse*5, 111111), m_body->GetWorldCenter(), true);
    }
    else
    {
        m_body->ApplyLinearImpulse(b2Vec2(-impulse*5, 111111), m_body->GetWorldCenter(), true);
    }
}
//----------------------------------------------------------------------------