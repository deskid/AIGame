#include <stdexcept>
#include <string>
#include <iostream>

#include <SDL.h>
#include "Game.h"

int main(int argc, char**argv){
	Game* gGame = new Game();

	gGame->init();


	while (gGame->isRunning()){

		gGame->handleEvent();
		gGame->updata();
		gGame->render();

	}
	gGame->close();

	return 0;
}