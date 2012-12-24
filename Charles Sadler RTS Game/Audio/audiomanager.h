//class from first year (or second)

#include<iostream>
#include<map>
#include<string>
using namespace std;

#include "SDL_mixer.h"
#include "SDL_draw.h"

typedef map<string, Mix_Chunk*> CMAP;
typedef map<string, Mix_Chunk*>::iterator CMAPIT;

class AudioManager
{
private:
	// Static variable of type AudioManager pointer
	static AudioManager* instance;

	// All constructors are declared private to prevent
	// it being used to create AudioManager objects
	// from outside the class
	AudioManager();

public:
	// Static (global) method to return the attribute
	// 'instance'. If instance is NULL it creates an
	// object of type AudioManager and stores it address
	// in the static attribute instance
	static AudioManager* getInstance();

	~AudioManager();


public:
	bool addSound(char* filename, string name);
	void playSound(string name);
	void stopSound();

private:
	// Map container to maintain collection of sounds
	CMAP soundmap;

};
