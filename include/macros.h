#pragma once
#include <SFML/Graphics.hpp>

constexpr auto STARTING_X = 50;
constexpr auto STARTING_Y = 348;
constexpr auto Extra = 65;
constexpr auto FOOT_LOC = 30;

constexpr auto limit= '|';
constexpr auto player = 'P';
constexpr auto player2 = 'p';
constexpr auto diff = 4000;
constexpr auto Board_Height = 700;
constexpr auto Board_Width = 928;
constexpr auto Game_time = 60;
constexpr auto EARTH_GRAVITY = -9.8f;
constexpr auto MOON_GRAVITY = -1.6f;
constexpr auto JUMP = 20;
constexpr auto STEP_SIZE = 15;
constexpr auto VOLUME = 50;

//--------texture and sounds enums------------------//
constexpr auto MOON_TEX =4 ;
constexpr auto WORLD_TEX = 2;
constexpr auto GOAL_SOUND = 0;
constexpr auto FANS_MUSIC = 0;
constexpr auto START_VEC = 0;
constexpr auto EXIT_VEC = 1;
constexpr auto HOW_TO_PLAY_VEC = 3;
constexpr auto FOOT_TEX = 1;
constexpr auto GOAL_TEX = 0;
constexpr auto PAUSE_TEX = 7;
constexpr auto MENU_BACKGROUND = 6;
constexpr auto GOAL_CELEBRATION = 5;
constexpr auto YETI_TEX = 3;
constexpr auto BACK_VEC = 2;
constexpr auto EXP_VEC = 4;
constexpr auto MAP_FRAME_VEC = 12;
constexpr auto FRAME_VEC = 11;
constexpr auto WORLD_VEC = 10;
constexpr auto MOON_VEC = 9;
constexpr auto BACK_NEXT_VEC = 2;
constexpr auto CHICKEN_VEC = 6;
constexpr auto SANTA_VEC = 7;
constexpr auto NERD_VEC = 5;
constexpr auto FOOTBALLPLAYER_VEC = 8;
constexpr auto NEW_GAME_VEC = 13;
constexpr auto WINNER_VEC = 14;
constexpr auto CONTINUE_VEC = 17;
constexpr auto BACKTO_VEC = 18;
constexpr auto QUIT_VEC = 19;
constexpr auto SPEAKER_ON = 8;
constexpr auto SPEAKER_OFF = 9;

//---------------------------------------//
enum MyEnum
{
	santa='s',
	football_player='f',
	ball='o',
	chicken= 'c',
	goal = '|',
	nerd='8'
};
