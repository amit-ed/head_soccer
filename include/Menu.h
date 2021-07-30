#pragma once
#include "Board.h"
#include <map>

//----------------------------------------------------------------------------
//base command class
class Command {
public:
	virtual bool execute() = 0; //execute is common to all commands
protected:
};
//----------------------------------------------------------------------------
class Menu
{
public:
	Menu(RenderWindow& window,char& p, char& p2, float &g );
	void add(Sprite& sprite, unique_ptr<Command> c, vector<shared_ptr<Texture>> v) {
		m_options.emplace_back(option(sprite, move(c), v));
	}		//adds a button to the menu
	bool showMenu();	
		//a while loop that keeps showing the menu untill clicking on back button

private:
	typedef tuple<Sprite&, unique_ptr<Command>, vector<shared_ptr<Texture>>> option;  //button
	typedef tuple<char&, char&, float&> user_selection;	
		//represent the data needed for the main program (which players selected and which stage)
	void handleClick(const sf::Vector2f& location, RenderWindow& window);
	void handleHover(const sf::Vector2f& location);

	RenderWindow& m_window;
	vector<option> m_options;	//all of the buttons and what they do (their command)
	user_selection m_selection;
	Sprite m_background;	//background is common to all menues
	bool m_close_curr = false, m_close_all = false; 
	//close curr is used to close this menu
	//close all is to exit back to the actual game
};
//----------------------------------------------------------------------------
//it's execute does nothing
class Blank :public Command
{
	bool execute() { return false; }
};
//----------------------------------------------------------------------------
//like Back, but also close all menues
class Next :public Command
{
	bool execute() { return true; }
};
//----------------------------------------------------------------------------
//a Command that tells the menu to return back
class Back :public Command
{
public:
	bool execute() { return true; }
};
//----------------------------------------------------------------------------
//a Command that when executed, simply close the window
class Exit :public Command
{
public:
	Exit(RenderWindow& window) : m_window(window) {};
	bool execute() { m_window.close(); return false; }

private:
	RenderWindow& m_window;
};
//----------------------------------------------------------------------------
//a Command that when executed, shows a menu with back button and "how to play" image
class How_to_play :public Command
{
public:
	How_to_play(RenderWindow& window, char& p, char& p2, float& g) : m_window(window), m_selection(user_selection(p, p2, g)) {};
	virtual bool execute() 
	{
		Sprite back, exp;
		back.setTexture(*Textures::instance().get_Texture_vector(BACK_NEXT_VEC)[0]);
		back.setPosition(20, 50);
		exp.setTexture(*Textures::instance().get_Texture_vector(EXP_VEC)[0]);
		Menu menu(m_window, get<0>(m_selection), get<1>(m_selection), get<2>(m_selection));
		exp.setPosition(20,150);
		menu.add(back, make_unique<Back>(), Textures::instance().get_Texture_vector(BACK_NEXT_VEC));
		menu.add(exp, make_unique<Blank>(), Textures::instance().get_Texture_vector(EXP_VEC));

		menu.showMenu();	//show the menu with the back button and howtoplay image
		return false;
	}
private:
	typedef tuple<char&, char&, float&> user_selection;
	RenderWindow& m_window;
	user_selection m_selection;
};
//----------------------------------------------------------------------------
//a Command that when executed, change it's T& var to be the other one's value.
//we use it to select either character(char)\map(float) so its a template class
template<class T>
class pick_player :public Command
{
public:
	pick_player(T& p, T p2, Vector2f loc, Sprite& sprite) : m_me(p2), def(p), m_loc(loc), m_sprite(sprite) {};
	bool execute()
	{
		m_sprite.setPosition(m_loc);
		def = m_me;
		return false;
	}

private:
	T m_me, & def;
	Vector2f m_loc;	//the frame location incase this button get chosen
	Sprite& m_sprite;	//the frame
};
//----------------------------------------------------------------------------
//the start button - its execute opens a menu with the character and map select options
class Start :public Command
{
public:
	Start(RenderWindow& window,char &p, char& p2,float &g) : m_window(window), m_selection(user_selection(p, p2, g)) {};
	virtual bool execute()
	{
		Sprite back, next, chicken1, chicken2, nerd1, nerd2, boy1, boy2, santa1, santa2, world, moon, frame, frame2, map_frame;
		map_frame.setTexture(*Textures::instance().get_Texture_vector(MAP_FRAME_VEC)[0]);
		frame.setTexture(*Textures::instance().get_Texture_vector(FRAME_VEC)[0]);
		frame2.setTexture(*Textures::instance().get_Texture_vector(FRAME_VEC)[0]);
		world.setTexture(*Textures::instance().get_Texture_vector(WORLD_VEC)[0]);
		moon.setTexture(*Textures::instance().get_Texture_vector(MOON_VEC)[0]);
		back.setTexture(*Textures::instance().get_Texture_vector(BACK_NEXT_VEC)[0]);
		next.setTexture(*Textures::instance().get_Texture_vector(BACK_NEXT_VEC)[0]);
		chicken1.setTexture(*Textures::instance().get_Texture_vector(CHICKEN_VEC)[0]);
		chicken2.setTexture(*Textures::instance().get_Texture_vector(CHICKEN_VEC)[0]);
		santa2.setTexture(*Textures::instance().get_Texture_vector(SANTA_VEC)[0]);
		santa1.setTexture(*Textures::instance().get_Texture_vector(SANTA_VEC)[0]);
		nerd2.setTexture(*Textures::instance().get_Texture_vector(NERD_VEC)[0]);
		nerd1.setTexture(*Textures::instance().get_Texture_vector(NERD_VEC)[0]);
		boy2.setTexture(*Textures::instance().get_Texture_vector(FOOTBALLPLAYER_VEC)[0]);
		boy1.setTexture(*Textures::instance().get_Texture_vector(FOOTBALLPLAYER_VEC)[0]);
		Menu menu(m_window, get<0>(m_selection), get<1>(m_selection), get<2>(m_selection));
		moon.scale(0.3, 0.3);
		world.scale(0.3, 0.3);
		next.scale(-1, 1);
		world.setPosition(0, 50);
		moon.setPosition(650, 50);
		back.setPosition(10, 500);
		next.setPosition(900, 500);
		chicken1.setPosition(320, 200);
		chicken2.setPosition(550, 200);
		santa1.setPosition(320, 300);
		santa2.setPosition(550, 300);
		boy1.setPosition(320, 400);
		boy2.setPosition(550, 400);
		nerd1.setPosition(320, 500);
		nerd2.setPosition(550, 500);
		map_frame.setPosition(world.getPosition());
		frame.setPosition(boy1.getPosition());
		frame2.setPosition(boy2.getPosition());
		menu.add(back, make_unique<Back>(), Textures::instance().get_Texture_vector(BACK_NEXT_VEC));
		menu.add(next, make_unique<Next>(), Textures::instance().get_Texture_vector(BACK_NEXT_VEC));
		menu.add(chicken1, make_unique<pick_player<char>>(get<0>(m_selection), 'c', chicken1.getPosition(), frame), Textures::instance().get_Texture_vector(CHICKEN_VEC));
		menu.add(chicken2, make_unique<pick_player<char>>(get<1>(m_selection), 'c', chicken2.getPosition(), frame2), Textures::instance().get_Texture_vector(CHICKEN_VEC));
		menu.add(boy1, make_unique<pick_player<char>>(get<0>(m_selection), 'f', boy1.getPosition(), frame), Textures::instance().get_Texture_vector(FOOTBALLPLAYER_VEC));
		menu.add(boy2, make_unique<pick_player<char>>(get<1>(m_selection), 'f', boy2.getPosition(), frame2), Textures::instance().get_Texture_vector(FOOTBALLPLAYER_VEC));
		menu.add(santa1, make_unique<pick_player<char>>(get<0>(m_selection), 's', santa1.getPosition(), frame), Textures::instance().get_Texture_vector(SANTA_VEC));
		menu.add(santa2, make_unique<pick_player<char>>(get<1>(m_selection), 's', santa2.getPosition(), frame2), Textures::instance().get_Texture_vector(SANTA_VEC));
		menu.add(nerd1, make_unique<pick_player<char>>(get<0>(m_selection), '8', nerd1.getPosition(), frame), Textures::instance().get_Texture_vector(NERD_VEC));
		menu.add(nerd2, make_unique<pick_player<char>>(get<1>(m_selection), '8', nerd2.getPosition(), frame2), Textures::instance().get_Texture_vector(NERD_VEC));
		menu.add(moon, make_unique<pick_player<float>>(get<2>(m_selection), -1.6, moon.getPosition(), map_frame), Textures::instance().get_Texture_vector(MOON_VEC));
		menu.add(world, make_unique<pick_player<float>>(get<2>(m_selection), -9.8, world.getPosition(), map_frame), Textures::instance().get_Texture_vector(WORLD_VEC));
		menu.add(map_frame, make_unique<Blank>(), Textures::instance().get_Texture_vector(MAP_FRAME_VEC));
		menu.add(frame, make_unique<Blank>(), Textures::instance().get_Texture_vector(FRAME_VEC));
		menu.add(frame2, make_unique<Blank>(), Textures::instance().get_Texture_vector(FRAME_VEC));
		return menu.showMenu();
	}

private:
	typedef tuple<char&, char&, float&> user_selection;
	RenderWindow& m_window;
	user_selection m_selection;
};