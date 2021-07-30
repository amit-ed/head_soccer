#pragma once
#include "../include/Moving_Objects/MovingObject.h"
#include <memory>
#include "../include/Moving_Objects/Players/Player.h"
/// <summary>
/// ball class in the game
/// </summary>
class Ball : public MovingObject
{
public:
    Ball(Vector2f loc = { 0, 0 }, b2World* m_world=nullptr);
    void draw(sf::RenderTarget& target) { target.draw(m_sprite); }
    void update(Time delta);//update sprite to body
    void kick_me(bool dir);//after collide with foot
    bool scored() { return m_scored;  }//return if some scored goal
    void score() { m_scored = true; m_sprite.move(toVector(m_dir).x * 2, 0);}
    void unscore() { m_scored = false; }//after updating the score

private:
    bool m_scored = false;//if someone scored me
    static bool m_registerit;
};