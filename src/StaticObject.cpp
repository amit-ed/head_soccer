#pragma once
#include "../include/Static_Objects/StaticObject.h"

StaticObject::StaticObject(Vector2f loc,  b2World* m_world, const Texture* tex) : Object(loc)
{
	m_sprite.setTexture(*tex);
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2));
    
    //--------physics----------
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;   //static body cannot be moved
    bodyDef.position.Set(m_sprite.getPosition().x, Board_Height - m_sprite.getPosition().y);
    m_body = m_world->CreateBody(&bodyDef);
    //-------------------------
}