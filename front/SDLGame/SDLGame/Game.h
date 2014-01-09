#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "window.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include <vector>
#include "GameObject.h"

class Game
{
private:
	bool running;
	int currentFrame;
	std::vector<GameObject*> vGameObjects;
	Game(void):running(true){};
	static Game* pInstance;
public:
	static Game* Instance()
	{
		if(pInstance==nullptr)
		{
			pInstance = new Game();
			return pInstance;
		}
		return pInstance;
	}
	~Game(void){};

	// init the SDL resourse 
	void init(void);

	// render the textures of the world 
	void render(void);

	//updata the data of game
	int update(void);

	// free the resouse 
	void close(void);

	// handle the key events and mouse event
	void handleEvent(void);

	bool isRunning(void){return running;};
	void quit(void){running = false;};

};


#endif