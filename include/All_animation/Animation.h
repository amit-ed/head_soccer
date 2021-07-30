#pragma once

#include "Direction.h"
#include "AnimationData.h"

#include <SFML/Graphics.hpp>
/// <summary>
/// class to control each moving  object animation
/// </summary>
class Animation
{
public:
    Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite);
    void direction(Direction dir);//update object animation 
    
    void update(sf::Time delta);//update object animation 

private:
    void update();

    const AnimationData& m_data;
    sf::Time m_elapsed = {};
    Direction m_dir = Direction::Stay;
    int m_index = 0;
    sf::Sprite& m_sprite;
};
