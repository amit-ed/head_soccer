#pragma once
#include "../include/All_animation/Animation.h"
#include "../include/All_animation/Resources.h"

const auto AnimationTime = sf::seconds(0.1f);

//----------------------------------------------------------------------------
Animation::Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite)
    : m_data(data), m_dir(dir), m_sprite(sprite)
{
    m_sprite.setTexture(Resources::instance().texture());
    update();
}
//----------------------------------------------------------------------------
void Animation::direction(Direction dir)
{
    if (m_dir == dir)
    {
        return;
    }
    m_dir = dir;
    m_index %= m_data.m_data.find(m_dir)->second.size();
}
//----------------------------------------------------------------------------
void Animation::update(sf::Time delta)
{
    m_elapsed += delta;
    if (m_elapsed >= AnimationTime)
    {
        m_elapsed -= AnimationTime;
        ++m_index;
        m_index %= m_data.m_data.find(m_dir)->second.size();
        update();
    }
}
//----------------------------------------------------------------------------
void Animation::update()
{
    m_sprite.setTextureRect(m_data.m_data.find(m_dir)->second[m_index]);
    
}

