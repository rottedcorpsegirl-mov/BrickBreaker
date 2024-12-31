#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>

using namespace std;
using namespace sf;

class SoundManager
{
public:
	bool loadSound(const string & key, const string& filePath);
	bool loadMusic(const string& filePath);

	void PlaySound(const string& key);
	void playBackgroundMusic();

	void stopBackgroundMusic();


	void setVolume(const string& key, float volume);
	void setMusicVolume(float);

	

private:
	
	unordered_map<string, SoundBuffer> soundBuffers;
	unordered_map<string, Sound> sounds;
	Music backgroundMusic;

};

