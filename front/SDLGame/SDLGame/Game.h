#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "window.h"
#include "TextureManager.h"
class Game
{
private:
	bool running;
	int currentFrame;
	
public:
	Game(void):running(true){};
	~Game(void){};

	// init the SDL resourse 
	void init(void);

	// render the textures of the world 
	void render(void);

	//updata the data of game
	int updata(void);

	// free the resouse 
	void close(void);

	// handle the key events and mouse event
	void handleEvent(void);

	bool isRunning(void){return running;};
	void quit(void){running = false;};

};


#endif