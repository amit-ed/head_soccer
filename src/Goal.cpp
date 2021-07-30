#pragma once
#include "../include/Static_Objects/Goal.h"
//----------------------------------------------------------------------------
bool Goal::m_registerit = Factory::registerit(goal, [](Vector2f loc, b2World* world, bool dir) ->
    std::unique_ptr<Object> { return std::make_unique<Goal>(loc, world, dir); });
//----------------------------------------------------------------------------
Goal::Goal(Vector2f loc, b2World* m_world,bool Dir)
    : StaticObject(loc,  m_world, &Textures::instance().get_Textures(GOAL_TEX))
{
    if (Dir) flip();
    //--------------------------physics settings------------------------------------------
    b2PolygonShape rec;
    rec.SetAsBox(m_sprite.getTexture()->getSize().x / 2 - 2.f,  m_sprite.getTexture()->getSize().y / 2);
    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &rec;
    m_fixture = m_body->CreateFixture(&fixtureDef);
    //-----------------------------------------------------------------------------------

    m_sprite.setPosition(m_body->GetPosition().x, Board_Height - m_body->GetPosition().y);
}

//----------------------------------------------------------------------------
//this is called when there's a collision between the goal and the ball
void Goal::penetrate()
{
    m_player->add_score(); //tell the player connected to this goal that he scored
}