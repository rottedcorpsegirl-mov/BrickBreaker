#include "SoundManager.h"

bool SoundManager::loadSound(const string& key, const string& filePath)
{
    SoundBuffer buffer;
    if (!buffer.loadFromFile(filePath)) {
       cerr << "error loading sound: " << filePath << endl;
       return false;
    }
   
    soundBuffers[key] = buffer;
    sounds[key].setBuffer(soundBuffers[key]);
    return true;
}

bool SoundManager::loadMusic(const string& filePath)
{
    if (!backgroundMusic.openFromFile(filePath))
    {
        cerr << "error loading music: " << filePath << endl;
        return false;
    }
    return true;
    
}

void SoundManager::PlaySound(const string& key)
{
    if (sounds.find(key) != sounds.end())
    {
        sounds[key].play();
    }
}

void SoundManager::playBackgroundMusic()
{
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
}

void SoundManager::stopBackgroundMusic()
{
    backgroundMusic.stop();
}

void SoundManager::setVolume(const string& key, float volume)
{
    if (sounds.find(key) != sounds.end())
    {
        sounds[key].setVolume(volume);
    }
}

void SoundManager::setMusicVolume(float volume)
{
    backgroundMusic.setVolume(volume);
}
