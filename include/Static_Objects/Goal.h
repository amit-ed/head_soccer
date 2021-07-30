#pragma once
#include "StaticObject.h"
#include "../include/Moving_Objects/Players/Player.h"
//goal object 
class Goal : public StaticObject
{
public:
    Goal(Vector2f loc = { 0, 0 }, b2World* m_world=nullptr,bool Dir=false);
    void penetrate();
    
    void get_my_player(Player* player) { m_player = player; }

private:
    bool m_penetrated = false;
    Player* m_player = nullptr;
    static bool m_registerit;
};