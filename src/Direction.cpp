#pragma once
#include "Direction.h"
#include "macros.h"
#include <stdexcept>
//----------------------------------------------------------------------------
Direction opposite(Direction dir)
{
    switch (dir)
    {
        case Direction::Up:
            return Direction::Down;
        case Direction::Down:
            return Direction::Up;
        case Direction::Right:
            return Direction::Left;
        case Direction::Left:
            return Direction::Right;
        case Direction::Stay:
            return Direction::Stay;
        default:
            throw std::runtime_error("Unknown direction");
    }
}
//----------------------------------------------------------------------------
//setting a value to each Direction (enum type)
sf::Vector2f toVector(Direction dir)
{
    switch (dir)
    {
        case Direction::Up:
            return {0, JUMP};
        case Direction::Down:
            return {0, 0 };
        case Direction::Right:
            return {STEP_SIZE, 0 };
        case Direction::Left:
            return {-STEP_SIZE, 0 };
        case Direction::Stay:
            return { 0, 0 };
        default:
            throw std::runtime_error("Unknown direction");
    }
}
