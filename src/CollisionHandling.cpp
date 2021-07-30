#pragma once
#include "CollisionHandling.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "../include/Moving_Objects/Players/Chicken.h"
#include "../include/Moving_Objects/Players/Nerd.h"
#include "../include/Moving_Objects/Players/Santa.h"
#include "../include/Moving_Objects/Players/Footballplayer.h"
#include "..//include/Static_Objects/Foot.h"
#include "../include/Moving_Objects/Ball.h"
#include "../include/Static_Objects/Goal.h"
#include "Sounds_E.h"


namespace // anonymous namespace — the standard way to make function "static"
{
    //=====================================================
    void YetiPlayer(Object& ball,
        Object& player)
    {
        dynamic_cast<Santa*>(&player)->collide();
    }
    //=====================================================
    // primary collision-processing functions
    void PlayerYeti(Object& player,
        Object& ball)
    {
        YetiPlayer(ball, player);
    }
    //=====================================================
    void BallFoot(Object& ball,
        Object& foot)
    {
        dynamic_cast<Ball*>(&ball)->kick_me(dynamic_cast<Foot*>(&foot)->get_dir());
    }
    //=====================================================
    // primary collision-processing functions
    void FootBall(Object& foot,
        Object& ball)
    {
        BallFoot(ball, foot);
    }
    //=====================================================
    void BallPlayer(Object& ball,
                 Object& player)
    {
      dynamic_cast<Player*>(&player)->collide();
      ball.make_sound();
    }
    //=====================================================
    // primary collision-processing functions
    void PlayerBall(Object& player,
        Object& ball)
    {
        BallPlayer(ball, player);
    }
    //=====================================================
    void GoalBall(Object& goal,
        Object& ball)
    {
        dynamic_cast<Goal*>(&goal)->penetrate();
        GoalBall(ball, goal);
    }

    //=====================================================
    void BallGoal(Object& ball,
        Object& goal)
    {
        dynamic_cast<Goal*>(&goal)->penetrate();
        dynamic_cast<Ball*>(&ball)->score();
    }
//=====================================================

using HitFunctionPtr = void (*)(Object&, Object&);
// typedef void (*HitFunctionPtr)(GameObject&, GameObject&);
using Key = std::pair<std::type_index, std::type_index>;
using HitMap = std::map<Key, HitFunctionPtr>;

HitMap initializeCollisionMap()
{
    HitMap phm;
    //============ball with player for sound=============
    phm[Key(typeid(Ball), typeid(Player))] = &BallPlayer;
    phm[Key(typeid(Player), typeid(Ball))] = &PlayerBall;
    phm[Key(typeid(Yeti), typeid(Santa))] = &YetiPlayer;
    phm[Key(typeid(Santa), typeid(Yeti))] = &PlayerYeti;
    phm[Key(typeid(Chicken), typeid(Ball))] = &PlayerBall;
    phm[Key(typeid(Ball), typeid(Chicken))] = &BallPlayer;
    phm[Key(typeid(Santa), typeid(Ball))] = &PlayerBall;
    phm[Key(typeid(Ball), typeid(Santa))] = &BallPlayer;
    phm[Key(typeid(Footballplayer), typeid(Ball))] = &PlayerBall;
    phm[Key(typeid(Ball), typeid(Footballplayer))] = &BallPlayer;
    phm[Key(typeid(Nerd), typeid(Ball))] = &PlayerBall;
    phm[Key(typeid(Ball), typeid(Nerd))] = &BallPlayer;
    //==================================================
    phm[Key(typeid(Ball), typeid(Goal))] = &BallGoal;
    phm[Key(typeid(Goal), typeid(Ball))] = &GoalBall;
    phm[Key(typeid(Ball), typeid(Foot))] = &BallFoot;
    phm[Key(typeid(Foot), typeid(Ball))] = &FootBall;
    //...
    return phm;
}

HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
{
    static HitMap collisionMap = initializeCollisionMap();
    auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
    if (mapEntry == collisionMap.end())
    {
        return nullptr;
    }
    return mapEntry->second;
}

} // end namespace

void processCollision(Object& object1, Object& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        return;// throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}
