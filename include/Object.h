#pragma once
#include "../include/All_animation/Animation.h"
#include "../include/All_animation/Resources.h"
#include "../include/All_animation/Textures.h"
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "macros.h"
#include <vector>
#include "box2d/box2d.h"
#include <SFML/Audio.hpp>
#include "Sounds_E.h"
#include "Factory.h"
using namespace sf;
using namespace std;
class Player;
class Ball;
class MovingObject;
//class for all the objects in the game(all types of ball,players and goal)
class Object
{
public:
	Object(Vector2f loc = {0, 0});//sets object loc
	virtual void draw(sf::RenderTarget& target) const { target.draw(m_sprite); }
	bool collide_with(const Object& other);//checks if 2 objects collide
	Direction get_dir() const{ return m_dir; }
	void flip() { m_sprite.scale(-1, 1); }//flips object dir if needed
	virtual void setloc(Vector2f loc = { 0, 0 }) { m_sprite.setPosition(loc); }
	~Object() { m_body->DestroyFixture(m_fixture);}
	void move_to_start();//move object to original location 
	void make_sound() { my_sound.play(); };//make object specific sound
	 const int return_score()const {};
protected:
	sf::Sprite m_sprite;
	vector<Texture*> m_textures;
	Direction m_dir = Direction::Stay;
	b2Body* m_body = nullptr;
	b2Fixture* m_fixture = nullptr;
	Vector2f m_firstloc;
	Sound my_sound;
};