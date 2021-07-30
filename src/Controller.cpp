#pragma once
#include "Controller.h"
#include <chrono>
#include <thread>
#include "Menu.h"
#include "Collision.hpp"
#include "All_animation/Textures.h"
//----------------------------------------------------------------------------
Controller::Controller() : m_window(sf::VideoMode(Board_Width, Board_Height), "Head Soccer") 
{ 
    m_goal_sound.setBuffer(Sounds_E::instance().get_Sounds(GOAL_SOUND));
    m_goal_sound.setVolume(VOLUME);
    m_bg.setTexture(Textures::instance().get_Textures(WORLD_TEX));
    m_pause.setTexture(Textures::instance().get_Textures(PAUSE_TEX));
    m_pause.setPosition(10, 40);
    m_music.setTexture(Textures::instance().get_Textures(SPEAKER_ON));
    m_music.setPosition(10, 120);
    makeMenu();
}
//----------------------------------------------------------------------------
void Controller::Run()
{
    srand(static_cast<unsigned>(time(nullptr)));
    
    while (m_window.isOpen())
    {
        m_window.clear();
        draw();
        m_window.display();
        handle_events();
        update_object();
     }
}
//----------------------------------------------------------------------------
void Controller::draw()
{
    m_window.draw(m_bg);
    m_board->draw(m_window);
    m_game_clock.draw(m_window);
    m_window.draw(m_pause);
    m_window.draw(m_music);
}
//----------------------------------------------------------------------------
void Controller::update_object()
{
    if (m_board->update_object(m_clock))
    {   //get in here if goal was scored
        m_goal_sound.play();
        while (true) {
            draw();
            if (m_score.draw(m_window))
                break;
            m_window.display();
        }
     
        this_thread::sleep_for(chrono::milliseconds(500));	//after a goal
        m_board->rebuild_Map();
    }

    if (!m_game_clock.update_time())   //if the timer got to 0
    {
        new_game_or_exit();
        m_game_clock.start_clock();
    }
}
//----------------------------------------------------------------------------
void Controller::handle_events()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event); )
    {
        switch (event.type)
        {
        case Event::Closed:
            m_window.close();
            break;
        case Event::MouseButtonReleased:
        {
            auto location = m_window.mapPixelToCoords(
                { event.mouseButton.x, event.mouseButton.y });

            switch(event.mouseButton.button)
            case Mouse::Button::Left:
            {    if (m_pause.getGlobalBounds().contains(location))
                {
                    m_game_clock.pause();
                    char a, b;
                    float c;
                    Sprite continu, quit, backtomenu;

                    continu.setPosition(Vector2f(240, 50));
                    backtomenu.setPosition(Vector2f(240, 200));
                    quit.setPosition(Vector2f(240, 350));

                    continu.setTexture(*Textures::instance().get_Texture_vector(CONTINUE_VEC)[0]);
                    backtomenu.setTexture(*Textures::instance().get_Texture_vector(BACKTO_VEC)[0]);
                    quit.setTexture(*Textures::instance().get_Texture_vector(QUIT_VEC)[0]);

                    Menu pause(m_window, a, b, c);  //open the pause menu
                    pause.add(continu, make_unique<Back>(), Textures::instance().get_Texture_vector(CONTINUE_VEC));
                    pause.add(backtomenu, make_unique<Next>(), Textures::instance().get_Texture_vector(BACKTO_VEC));
                    pause.add(quit, make_unique<Exit>(m_window), Textures::instance().get_Texture_vector(QUIT_VEC));
                    //add the continue button, back to menu button or quit button
                    if (pause.showMenu())
                    {
                        Sounds_E::instance().get_Music(FANS_MUSIC).pause();
                        makeMenu();
                        return;
                    }
                    m_game_clock.start();
                }
                if (m_music.getGlobalBounds().contains(location))
                {   //stop the music or continue it if paused
                    if (Sounds_E::instance().get_Music(FANS_MUSIC).getStatus() == Music::Status::Playing) {
                        m_music.setTexture(Textures::instance().get_Textures(SPEAKER_OFF));
                        Sounds_E::instance().get_Music(FANS_MUSIC).pause();
                    }
                    else
                    {
                        m_music.setTexture(Textures::instance().get_Textures(SPEAKER_ON));
                        Sounds_E::instance().get_Music(FANS_MUSIC).play();
                    }
                }
                break;
            }
            break;
        }
        }
    }
}
//----------------------------------------------------------------------------
//make the basic main menu that have 3 buttons - start the game, how to play and exit
void Controller::makeMenu()
{
    m_music.setTexture(Textures::instance().get_Textures(SPEAKER_ON));
    char p= football_player,  p2 = football_player;
    float a = EARTH_GRAVITY;
    Menu menu(m_window, p, p2, a);
    Sprite exit, start, howto;
   
    exit.setPosition(Vector2f(270, 480));
    start.setPosition(Vector2f(270, 50));
    howto.setPosition(Vector2f(116, 275));
    start.setTexture(*Textures::instance().get_Texture_vector(START_VEC)[0]);
    exit.setTexture(*Textures::instance().get_Texture_vector(EXIT_VEC)[0]);
    howto.setTexture(*Textures::instance().get_Texture_vector(HOW_TO_PLAY_VEC)[0]);

    menu.add(start, make_unique<Start>(m_window, p, p2, a), Textures::instance().get_Texture_vector(START_VEC));
    menu.add(howto, make_unique<How_to_play>(m_window, p, p2, a), Textures::instance().get_Texture_vector(HOW_TO_PLAY_VEC));
    menu.add(exit, make_unique<Exit>(m_window), Textures::instance().get_Texture_vector(EXIT_VEC));
    
    menu.showMenu();

    //if the players selected the moon map
    if (abs(a - MOON_GRAVITY) < 1) m_bg.setTexture(Textures::instance().get_Textures(MOON_TEX));
    else m_bg.setTexture(Textures::instance().get_Textures(WORLD_TEX));

    m_board = make_unique<Board>(p, p2, a);
    Sounds_E::instance().get_Music(FANS_MUSIC).play();
    m_game_clock.start_clock();
}
//----------------------------------------------------------------------------
void Controller::new_game_or_exit()
{  
    Sounds_E::instance().get_Music(FANS_MUSIC).stop();
    char p = football_player, p2 = football_player;
    float a = EARTH_GRAVITY;
    Menu menu(m_window, p, p2, a);  //make a new menu
    Sprite exit, next,winner; //buttons for the menu
    exit.setPosition(Vector2f(50, 350));
    next.setPosition(Vector2f(450, 350));
    winner.setPosition(Vector2f(240, 50));

    next.setTexture(*Textures::instance().get_Texture_vector(NEW_GAME_VEC)[0]);
    exit.setTexture(*Textures::instance().get_Texture_vector(EXIT_VEC)[0]);
    winner.setTexture(*Textures::instance().get_Texture_vector(WINNER_VEC+ m_board.get()->return_score_leader())[0]);

    menu.add(next, make_unique<Next>(), Textures::instance().get_Texture_vector(NEW_GAME_VEC));
    menu.add(exit, make_unique<Exit>(m_window), Textures::instance().get_Texture_vector(EXIT_VEC));
    menu.add(winner, make_unique<Blank>(), Textures::instance().get_Texture_vector(WINNER_VEC + m_board.get()->return_score_leader()));
    if(menu.showMenu())
       makeMenu();
}
//----------------------------------------------------------------------------