#pragma once
#include <vector>
#include "../include/Static_Objects/Goal.h"
#include "../include/Moving_Objects/Players/Player.h"
#include "macros.h"
#include <memory>
#include <fstream>
#include <iostream>
#include <string>
#include "CollisionHandling.h"
#include "Sounds_E.h"
using namespace std;
using namespace sf;
//Board class scan the file and build all the graphic objects

class ball;
class Chicken;
class Footballplayer;
class Nerd;
class Santa;
class Board
{
public:
	Board(char symbol1= football_player, char symbol2 = football_player,float g= EARTH_GRAVITY);
	~Board();
	bool set_Map();
	template <typename FwdIt, typename Fn>
	void for_each_pair(FwdIt begin, FwdIt end, Fn fn);//template STL algo to run all all the pairs
	void rebuild_Map();//rebuild the game map
	void build_map(char symbol1, char symbol2);//runs on map.txt and build the map
	void draw(RenderWindow& m_window);//draw
	bool update_object(Clock& m_clock);//update each object loc each itereition
	void connect_player_to_goal(int goal,int player);//so we know to add score to corrent player if scored 
	int  return_score_leader();//info to controller about the winner
private:
	int m_ball_place = 0;
	ifstream m_file;
	Vector2i m_size;
	vector<string> m_Board;
	unique_ptr<b2World> m_world;
	vector<unique_ptr<Object>> m_objects;
};

// STL-like algorithm to run over all pairs
template <typename FwdIt, typename Fn>
void Board::for_each_pair(FwdIt begin, FwdIt end, Fn fn)
{
	for (; begin != end; ++begin)
		for (auto second = begin + 1; second != end; ++second)
			fn(*begin, *second);
}