#pragma once
#include "Sounds_E.h"

 Sounds_E& Sounds_E:: instance() {
	 static Sounds_E  all_S;
	return all_S;
}
 //set the sound once for the game,just once!!!
Sounds_E::Sounds_E()
{
	std::vector<string>names = { 
			"goalsound.wav",
			"ballsound.wav"
	};
	
	sf::SoundBuffer sound;
	
	for (int i = 0; i < names.size(); i++) {
			if (!sound.loadFromFile(names[i])) {
				string temp = "couldnt load sound" + names[i];
				throw exception(temp.c_str());
			}
			m_gameSounds.insert(std::pair<int, sf::SoundBuffer>(i, sound));
	}
	shared_ptr < Music> cur=make_shared<Music>();
	if (!cur->openFromFile("Backsound.wav")) {
		string temp = "couldnt load sound";
		throw exception(temp.c_str());
	}
	m_music.emplace_back(cur);
	m_music[0].get()->setLoop(true);
	m_music[0].get()->setVolume(2);
}
//----------------------------------------------------------------------------
Sounds_E::~Sounds_E()
{
	m_Sounds.clear();
	m_music.clear();
	m_gameSounds.clear();
}
//----------------------------------------------------------------------------
