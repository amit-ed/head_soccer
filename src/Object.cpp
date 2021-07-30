#pragma once
#include "Object.h"
#include <iostream>
#include "Collision.hpp"
#include "../include/Moving_Objects/Ball.h"
//----------------------------------------------------------------------------
Object::Object(Vector2f loc)
{
	m_sprite.setPosition(loc);
    m_firstloc = loc;
}
//----------------------------------------------------------------------------
//check collision of 2 objects
//using a library that check perfect collision
bool Object::collide_with(const Object& other)
{
    return Collision::PixelPerfectTest(this->m_sprite, other.m_sprite);
}
//----------------------------------------------------------------------------
void Object::move_to_start()
{   //reset the object to where it began (for a new round)
    m_sprite.setPosition(m_firstloc);
    m_body->SetAwake(false);
    m_body->SetTransform(b2Vec2(m_sprite.getPosition().x, Board_Height - m_sprite.getPosition().y),0);
    m_body->SetAwake(true);
    if (typeid(*this) == typeid(Ball))  //rebounce the ball
        m_body->ApplyForce(b2Vec2(0, 3000000), b2Vec2(m_sprite.getPosition().x, Board_Height - m_sprite.getPosition().y), true);
}
//----------------------------------------------------------------------------