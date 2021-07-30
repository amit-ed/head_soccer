#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;
#pragma once
/// <summary>
/// singelton type class for all the sounds
/// </summary>
class Sounds_E{
	
	//--------------public--------functions-----------------------//
public:
	static Sounds_E& instance();
	//gets requested sound from sound member
	const sf::SoundBuffer& get_Sounds(int key) { return (m_gameSounds[key]); }
	  sf::Music & get_Music(int song_Num) { return (*m_music[song_Num]); }
	//--------------private--------functions-----------------------//		
private:

	//------------------members-----------------------------------//		
private:
		Sounds_E();//constractor for static member
		~Sounds_E();
		std::map<int, sf::SoundBuffer> m_gameSounds;
		vector<shared_ptr<Sound>>m_Sounds;
		 vector<shared_ptr<Music>>m_music;
		
};
