#pragma once
#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <string>
#include "box2d/box2d.h"
#include <SFML/Graphics.hpp>
using namespace sf;
/// <summary>
/// Generic solution for adding new objects to the game 
/// </summary>
class Object;

class Factory {
public:
	using pFnc = std::unique_ptr<Object>(*)(Vector2f loc, b2World* world ,bool dir );
	static std::unique_ptr<Object> create( char name, Vector2f loc, b2World* world, bool dir);//create new object
	static bool registerit( char name, pFnc);//add object option to object list in game
private:
	static auto& getMap() {
		static std::map<char, pFnc> map;
		return map;
	}
};
