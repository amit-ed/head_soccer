#pragma once
#include "Direction.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
/// <summary>
/// Data Structure to controll dir and appropriate animation
/// </summary>
struct AnimationData
{
    using ListType = std::vector<sf::IntRect>;
    using DataType = std::unordered_map<Direction, ListType>;
    DataType m_data;
};
