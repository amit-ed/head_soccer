#pragma once
#include "Object.h"
//class to controll all the static object
class StaticObject : public Object
{
public:
	StaticObject(Vector2f loc = { 0,0 },  b2World* m_world=nullptr, const Texture* tex = nullptr);

protected:
};