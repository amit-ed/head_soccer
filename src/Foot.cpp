#pragma once
#include "../include/Static_Objects/Foot.h"
//----------------------------------------------------------------------------
Foot::Foot(Vector2f loc, b2World* m_world, bool Dir)
    : StaticObject(Vector2f(0, 0), m_world, &Textures::instance().get_Textures(FOOT_TEX))
{
    if (!Dir) flip();
    m_sprite.setPosition(m_body->GetPosition().x, Board_Height - m_body->GetPosition().y);
}