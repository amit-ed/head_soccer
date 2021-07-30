#pragma once
#include "Game_clock.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
#include "ScoreAnimation.h"
class Controller
{
public:
	Controller();
	void Run();
	~Controller() {};
private:
	void makeMenu();//print first menu to user
	void new_game_or_exit();//after game ended give to user option to return to the menu or to end the game
	void draw();//draw
	void update_object();//ubdate all object related to controller
	void handle_events();//handle pause or exiting the window
	Sprite m_bg, m_pause, m_music;
	unique_ptr<Board> m_board;
	RenderWindow m_window;
	Clock m_clock = Clock();//for movement
	Game_clock m_game_clock;//real game time
	ScoreAnimation m_score;
	Sound m_goal_sound;
};