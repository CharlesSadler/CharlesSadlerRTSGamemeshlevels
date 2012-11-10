
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "sdl.h"
#include "sdl_mixer.h"

#include "awfont.h"
#include "audiomanager.h"
#include "console.h"

using namespace con;


//screen dimensions
const int SCREEN_WIDTH=400;
const int SCREEN_HEIGHT=200;

//display surface
SDL_Surface* g_pDisplaySurface = NULL;

//event structure
SDL_Event g_Event;

bool quit = false;

//main function
int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	// Initialise background graphic
	SDL_Surface* screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0,
		SDL_HWSURFACE | SDL_DOUBLEBUF); // | SDL_NOFRAME);


	if (screen == NULL)
	{
		cout << "Could not set up display surface!\n";
		exit(1);
	}
	else
	{
		cout << "SDL OK!\n";
		atexit(SDL_Quit);
	}
	console.setSize(20,10,true);

	AWFont* font1= new AWFont("vera_green.bmp", "vera.dat");

	AudioManager::getInstance()->addSound("birdsong.wav", "BIRD");
	AudioManager::getInstance()->addSound("carhorn.wav", "HORN");
	AudioManager::getInstance()->addSound("dog.wav", "DOG");
	AudioManager::getInstance()->addSound("pingpong.wav", "PINGPONG");
	AudioManager::getInstance()->addSound("seaside.wav", "SEASIDE");
	AudioManager::getInstance()->addSound("song.wav", "SONG");
	AudioManager::getInstance()->addSound("thunder.wav", "THUNDER");


	//repeat forever
	while(!quit)
	{
		SDL_Delay(10);
		if(SDL_PollEvent(&g_Event)){
			switch(g_Event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch(g_Event.key.keysym.sym)
				{
				case SDLK_F1:
					AudioManager::getInstance()->playSound("SONG");
					break;
				case SDLK_F2:
					AudioManager::getInstance()->playSound("BIRD");
					break;
				case SDLK_F3:
					AudioManager::getInstance()->playSound("HORN");
					break;
				case SDLK_F4:
					AudioManager::getInstance()->playSound("DOG");
					break;
				case SDLK_F5:
					AudioManager::getInstance()->playSound("SEASIDE");
					break;
				case SDLK_F6:
					AudioManager::getInstance()->playSound("PINGPONG");
					break;
				case SDLK_F7:
					AudioManager::getInstance()->playSound("THUNDER");
					break;
				case SDLK_ESCAPE:
					quit = true;
					break;
				}	// end of key event switch
				break;	// end default		
			}// end of poll event switch
		}// end if
		font1->print_string("Press F1 to F7 to play a sound", 30,30);
		font1->print_string("Press <esc> to exit program", 30,70);
		SDL_Flip(screen);

	}

	delete font1;
	delete AudioManager::getInstance();
	return(0);
}
