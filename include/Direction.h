#pragma once

#include <SFML/Graphics.hpp>
//class to make it easier to controll player and animation dir
enum class Direction
{
    Up,
    Down,
    Right,
    Left,
    Stay,
    Max,
};

Direction opposite(Direction dir);
sf::Vector2f toVector(Direction dir);
