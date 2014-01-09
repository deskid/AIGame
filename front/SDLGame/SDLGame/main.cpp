#include <stdexcept>
#include <string>
#include <iostream>

#include <SDL.h>
#include "Game.h"


const int FPS = 60;
const int DELAY_TIME = 1000.0f/FPS;

int main(int argc, char**argv){

	Uint32 frameStart, frameTime;

	Game::Instance()->init();


	while (Game::Instance()->isRunning()){

		frameStart = SDL_GetTicks();

		Game::Instance()->handleEvent();
		Game::Instance()->update();
		Game::Instance()->render();

		frameTime = SDL_GetTicks() - frameStart;

		if(frameTime< DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}

	}
	Game::Instance()->close();

	return 0;
}