#pragma once
#include "Board.h"
#include "../include/Moving_Objects/Ball.h"
#include "../include/Moving_Objects/Players/Santa.h"

//----------------------------------------------------------------------------
Board::Board(char symbol1 , char symbol2 , float g)
{
	m_file.open("map.txt");
	if (!m_file) throw std::runtime_error("Exception opening file\n");
	set_Map();

	//----------------------------------world------------------------------
	b2Vec2 gravity(0.0f, g);
	m_world = make_unique<b2World>(gravity);
	//----------------------------------ground------------------------------
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, 118.0f);
	b2Body* groundBody = m_world->CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(10000.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &groundBox;
	groundBody->CreateFixture(&fixtureDef);
	groundBody->SetFixedRotation(true);
	//------------------------sky--------------------------------------------------
	b2BodyDef skyBodyDef;
	skyBodyDef.position.Set(0.0f, 660.0f);
	b2Body* skyBody = m_world->CreateBody(&skyBodyDef);	
	
	skyBody->CreateFixture(&fixtureDef);
	//------------------------wall--------------------------------------------
	b2BodyDef wallBodyDef;
	wallBodyDef.position.Set(94.0f, 0.0f);
	b2Body* wallBody = m_world->CreateBody(&wallBodyDef);
	b2PolygonShape wallBox;
	wallBox.SetAsBox(19.f, 1000.0f);
	
	fixtureDef.shape = &wallBox;
	
	wallBody->CreateFixture(&fixtureDef);

b2BodyDef wall2BodyDef;
wall2BodyDef.position.Set(832.0f, 0.0f);
b2Body* wall2Body = m_world->CreateBody(&wall2BodyDef);

wall2Body->CreateFixture(&fixtureDef);
//----------------------------------ground----------------------------
build_map(symbol1,symbol2);
}
//----------------------------------------------------------------------------
Board::~Board()
{
	m_Board.clear();
}
//----------------------------------------------------------------------------
bool Board::set_Map()
{
	std::string temp = "";
	while ((temp == "" || temp == '\n'))
	{
		std::getline(m_file, temp);
		if (temp == "//")
			return false;
	}
	m_size.y = temp.length();
	int counter = 0;
	while (temp != "" && temp != '\n')
	{
		if (temp.length() != m_size.y) throw exception("error reading the map, need to fill blank with empty space\n");
		m_Board.push_back(temp);
		counter++;
		getline(m_file, temp);
	}
	m_size.x = counter;
	return (!m_file.fail());
}
//----------------------------------------------------------------------------
int  Board::return_score_leader()
{
	int winner, first_player_score=0, second_player_score = 0;
	bool first = true;
	for (auto& x : m_objects)
		if (auto y = (dynamic_cast<Player*>(x.get())))
		{
			if (first) {
				first_player_score = y->return_score();
				first = false;
			}
			else second_player_score = y->return_score();
		}
	winner= first_player_score - second_player_score ;
	if (winner > 0)
		return 1;
	if (winner < 0)
		return 2;
	if (winner == 0)
		return 0;
}
//----------------------------------------------------------------------------
void Board::build_map(char symbol1, char symbol2)
{
	float length =
		(Board_Width / float(m_size.y) + Board_Height / float(m_size.x)) / 5;  //calculated space between objects
	int player1_place=0, player2_place=0, Goalright_place=0, GoalLeft_place=0;

	bool first_goal = true, first_player = true,dir=true;
	for (int i = 0; i < m_size.x; i++) {

		for (int j = 0; j < m_size.y; j++) {
			Vector2f location(STARTING_X + (j * length),
							STARTING_Y + (i * length));
			if (m_Board[i][j] == ' ') continue;
			dir = true;
			if (m_Board[i][j] == 'p')
				if (first_player) { first_player = false; player1_place = m_objects.size(); m_Board[i][j] = symbol1; }
				else { player2_place = m_objects.size(); dir = false; m_Board[i][j] = symbol2; }
			else if (m_Board[i][j] == '|')
				if (first_goal) { first_goal = false; GoalLeft_place = m_objects.size(); }
				else { Goalright_place = m_objects.size(); dir = false; }
			else if (m_Board[i][j] != 'o') throw exception("unknown symbol in map.txt");
			m_objects.emplace_back( Factory::create(m_Board[i][j],location,m_world.get(),dir));
		}
	}
	
	connect_player_to_goal(GoalLeft_place, player2_place);
	connect_player_to_goal(Goalright_place,player1_place);
}
//----------------------------------------------------------------------------
void Board::connect_player_to_goal(int goal, int player)
{
	if (auto x = dynamic_cast<Goal*>(m_objects[goal].get()))
	{
		if (auto y = (dynamic_cast<Player*>(m_objects[player].get())))
		{
			x->get_my_player(y);
		}
	}
}
//----------------------------------------------------------------------------
// restart all objects to refresh the stage
void Board::rebuild_Map() {
	
	for (auto &x : m_objects)
		x.get()->move_to_start();
}
//----------------------------------------------------------------------------
void Board::draw(RenderWindow &m_window)
{
	for (auto &x : m_objects)
		x.get()->draw(m_window);
}
//----------------------------------------------------------------------------
namespace {
	
	bool collide(Object& a, Object& b)
	{
		return a.collide_with(b);
	}
}
//----------------------------------------------------------------------------
bool Board::update_object(Clock &m_clock)
{
	if (dynamic_cast<Ball*>(m_objects[m_ball_place].get())->scored())
	{
		dynamic_cast<Ball*>(m_objects[m_ball_place].get())->unscore();
		return true;
	}
	
	m_world->Step(1.0f / 60.0f, 8, 3);
	auto delta = m_clock.restart();
	for (auto& x : m_objects)
	{	//update all objects
		if (dynamic_cast<MovingObject*>((x.get())))
		{
			dynamic_cast<MovingObject*>((x.get()))->update(delta);
		}
	}

	//check collision between every object pair in the object vector
	for_each_pair(m_objects.begin(), m_objects.end(), [](auto& a, auto& b) {
		if (collide(*a.get(), *b.get()))
		{
			processCollision(*a, *b);
		}
		});

	//because the foots and yeti isn't in the object vector they need a seperate check 
	for_each_pair(m_objects.begin(), m_objects.end(), [](auto& a, auto& b) {kick_collision(a.get(), b.get()); });
	for_each_pair(m_objects.begin(), m_objects.end(), [](auto& a, auto& b) {yeti_collision(a.get(), b.get()); });

	return false;
}
//----------------------------------------------------------------------------
namespace
{
	void kick_collision(Object* a, Object* b)
	{
		{
			Foot* temp;
			if (dynamic_cast<Player*>(a))
			{
				temp = dynamic_cast<Player*>(a)->get_foot();
				if (collide(*temp, *b))
				{
					processCollision(*temp, *b);
				}
			}
			else if (dynamic_cast<Player*>(b))
			{
				temp = dynamic_cast<Player*>(b)->get_foot();

				if (collide(*a, *temp))
				{
					processCollision(*a, *temp);
				}
			}}
	}

	void yeti_collision(Object* a, Object* b)
	{
		{
			Yeti* temp;
			if (dynamic_cast<Santa*>(a))
			{
				temp = dynamic_cast<Santa*>(a)->get_yeti();
				if (collide(*temp, *b))
				{
					processCollision(*temp, *b);
				}
				if (collide(*temp, *a))
				{
					processCollision(*temp, *a);
				}
			}
			else if (dynamic_cast<Santa*>(b))
			{
				temp = dynamic_cast<Santa*>(b)->get_yeti();

				if (collide(*a, *temp))
				{
					processCollision(*a, *temp);
				}
				if (collide(*b, *temp))
				{
					processCollision(*b, *temp);
				}
			}
		}
	}
}
//----------------------------------------------------------------------------