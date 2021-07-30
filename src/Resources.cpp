#pragma once
#include "../include/All_animation/Resources.h"
#include "Direction.h"
#include <stdexcept>
//----------------------------------------------------------------------------
namespace
{
    AnimationData BallData()
    {
        const auto size = sf::Vector2i(39, 39);
        const auto initSpace = sf::Vector2i(5, 91);
        const auto middleSpace = sf::Vector2i(5, 0);

        auto ball = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };

        ball.m_data[Direction::Right].emplace_back(currentStart, size);
        ball.m_data[Direction::Right].emplace_back(nextStart(), size);
        ball.m_data[Direction::Right].emplace_back(nextStart(), size);
        ball.m_data[Direction::Right].emplace_back(nextStart(), size);
        ball.m_data[Direction::Right].emplace_back(nextStart(), size);
        ball.m_data[Direction::Right].emplace_back(nextStart(), size);
        ball.m_data[Direction::Right].emplace_back(nextStart(), size);
        ball.m_data[Direction::Right].emplace_back(nextStart(), size);
        ball.m_data[Direction::Right].emplace_back(nextStart(), size);
        ball.m_data[Direction::Right].emplace_back(nextStart(), size);
        ball.m_data[Direction::Left] = ball.m_data[Direction::Right];
        ball.m_data[Direction::Up] = ball.m_data[Direction::Right];
        ball.m_data[Direction::Down] = ball.m_data[Direction::Right];
        ball.m_data[Direction::Stay].emplace_back(currentStart, size);
       
        return ball;
    }
    //----------------------------------------------------------------------------
    AnimationData smallBallData()
    {
        const auto size = sf::Vector2i(27, 27);
        const auto initSpace = sf::Vector2i(10, 8);
        const auto middleSpace = sf::Vector2i(18, 0);

        auto Smallball = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };

        Smallball.m_data[Direction::Right].emplace_back(currentStart, size);
        Smallball.m_data[Direction::Right].emplace_back(nextStart(), size);
        Smallball.m_data[Direction::Right].emplace_back(nextStart(), size);
        Smallball.m_data[Direction::Right].emplace_back(nextStart(), size);
        Smallball.m_data[Direction::Right].emplace_back(nextStart(), size);
        Smallball.m_data[Direction::Right].emplace_back(nextStart(), size);
        Smallball.m_data[Direction::Right].emplace_back(nextStart(), size);
        Smallball.m_data[Direction::Right].emplace_back(nextStart(), size);
        Smallball.m_data[Direction::Right].emplace_back(nextStart(), size);
        Smallball.m_data[Direction::Right].emplace_back(nextStart(), size);
        Smallball.m_data[Direction::Left] = Smallball.m_data[Direction::Right];
        Smallball.m_data[Direction::Up] = Smallball.m_data[Direction::Right];
        Smallball.m_data[Direction::Down] = Smallball.m_data[Direction::Right];


        return Smallball;
    }
    //----------------------------------------------------------------------------
    AnimationData PlayerData()
    {
        auto size = sf::Vector2i(55, 83);
        auto initSpace = sf::Vector2i(11, 298);
        auto middleSpace = sf::Vector2i(18, 0);

        auto Player = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };

        Player.m_data[Direction::Right].emplace_back(currentStart, size);
        Player.m_data[Direction::Right].emplace_back(nextStart(), size);
        Player.m_data[Direction::Right].emplace_back(nextStart(), size);
        Player.m_data[Direction::Left] = Player.m_data[Direction::Right];  

        size = sf::Vector2i(55, 83);
        initSpace = sf::Vector2i(6, 394);
        middleSpace = sf::Vector2i(18, 0);
        currentStart = initSpace;

        Player.m_data[Direction::Stay].emplace_back(currentStart, size);
        Player.m_data[Direction::Stay].emplace_back(nextStart(), size);
        Player.m_data[Direction::Stay].emplace_back(nextStart(), size);
        

        size = sf::Vector2i(55, 83);
        initSpace = sf::Vector2i(6, 200);
        middleSpace = sf::Vector2i(18, 0);
        currentStart = initSpace;

        Player.m_data[Direction::Up].emplace_back(currentStart, size);
        Player.m_data[Direction::Up].emplace_back(nextStart(), size);
        Player.m_data[Direction::Up].emplace_back(nextStart(), size);

        return Player;
    }
    //----------------------------------------------------------------------------
    AnimationData SantaData()
    {
        auto size = sf::Vector2i(50, 81);
        auto initSpace = sf::Vector2i(438, 500);
        auto middleSpace = sf::Vector2i(24, 0);

        auto Player = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };

        Player.m_data[Direction::Right].emplace_back(currentStart, size);
        Player.m_data[Direction::Right].emplace_back(nextStart(), size);
        Player.m_data[Direction::Right].emplace_back(nextStart(), size);
        Player.m_data[Direction::Left] = Player.m_data[Direction::Right];


        size = sf::Vector2i(52, 84);
        initSpace = sf::Vector2i(433, 595);
        middleSpace = sf::Vector2i(22, 0);
        currentStart = initSpace;

        Player.m_data[Direction::Stay].emplace_back(currentStart, size);
        Player.m_data[Direction::Stay].emplace_back(nextStart(), size);
        Player.m_data[Direction::Stay].emplace_back(nextStart(), size);


        size = sf::Vector2i(52, 83);
        initSpace = sf::Vector2i(433, 403);
        middleSpace = sf::Vector2i(21, 0);
        currentStart = initSpace;

        Player.m_data[Direction::Up].emplace_back(currentStart, size);
        Player.m_data[Direction::Up].emplace_back(nextStart(), size);
        Player.m_data[Direction::Up].emplace_back(nextStart(), size);

        return Player;
    }
    //----------------------------------------------------------------------------
    AnimationData ChickenData()
    {
        auto size = sf::Vector2i(49, 84);
        auto initSpace = sf::Vector2i(230, 182);
        auto middleSpace = sf::Vector2i(21, 0);

        auto Player = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };

        Player.m_data[Direction::Right].emplace_back(currentStart, size);
        Player.m_data[Direction::Right].emplace_back(nextStart(), size);
        Player.m_data[Direction::Right].emplace_back(nextStart(), size);
        Player.m_data[Direction::Left] = Player.m_data[Direction::Right];
        Player.m_data[Direction::Stay] = Player.m_data[Direction::Right];
        

        size = sf::Vector2i(70, 87);
        initSpace = sf::Vector2i(217, 357);
        middleSpace = sf::Vector2i(0, 0);
        currentStart = initSpace;

        Player.m_data[Direction::Up].emplace_back(currentStart, size);
        Player.m_data[Direction::Up].emplace_back(nextStart(), size);
        Player.m_data[Direction::Up].emplace_back(nextStart(), size);

        return Player;
    }
    //----------------------------------------------------------------------------
    AnimationData NerdData()
    {
        auto size = sf::Vector2i(48, 78);
        auto initSpace = sf::Vector2i(463, 102);
        auto middleSpace = sf::Vector2i(27, 0);

        auto Player = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };

        Player.m_data[Direction::Right].emplace_back(currentStart, size);
        Player.m_data[Direction::Right].emplace_back(nextStart(), size);
        Player.m_data[Direction::Right].emplace_back(nextStart(), size);
        Player.m_data[Direction::Left] = Player.m_data[Direction::Right];
        Player.m_data[Direction::Up] = Player.m_data[Direction::Right];

        size = sf::Vector2i(53, 78);
        initSpace = sf::Vector2i(456, 204);
        middleSpace = sf::Vector2i(23, 0);
        currentStart = initSpace;

        Player.m_data[Direction::Stay].emplace_back(currentStart, size);
        Player.m_data[Direction::Stay].emplace_back(nextStart(), size);
        Player.m_data[Direction::Stay].emplace_back(nextStart(), size);

        return Player;
    }
    //----------------------------------------------------------------------------
}
//----------------------------------------------------------------------------
Resources& Resources::instance()
{
    static Resources instance;
    return instance;
}
//----------------------------------------------------------------------------
Resources::Resources()
    : m_data(Max)
{
    if (!m_texture.loadFromFile("spritesheet.png"))
    {
        throw std::runtime_error("Can't load file spritesheet.png");
    }
    m_data[smallBall] = smallBallData();
    m_data[Ball] = BallData();
    m_data[Player] = PlayerData();
    m_data[Santa] = SantaData();
    m_data[Chicken] = ChickenData();
    m_data[Nerd] = NerdData();
}
