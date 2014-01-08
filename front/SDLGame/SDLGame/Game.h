#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "window.h"

class Game
{
private:
	bool running;
	SDL_Texture *gBackground, *msg;
	SDL_Rect pos;
public:
	Game(void):running(true){};
	~Game(void){};

	// init the SDL resourse 
	void init(void);


	//load media and texture
	void loadMedia(void);

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