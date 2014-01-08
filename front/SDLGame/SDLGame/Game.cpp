#include "Game.h"
#include <iostream>

void Game::init(void)
{
	try {
		Window::Init("AI Magic Land");
		TextureManager::Instance()->load("resource/pics/fire.png","fire");
	}
	catch (const std::runtime_error &e){
		std::cout << e.what() << std::endl;
		Window::Quit();

	}
}



void Game::render(void)
{
	//RENDERING
	Window::Clear();

	TextureManager::Instance()->draw("fire",0,0,72,72);
	TextureManager::Instance()->drawFrame("fire",100,200,72,50,72,1,currentFrame);

	Window::Present();
}


int Game::updata(void)
{
	currentFrame =  int(((SDL_GetTicks() / 100) % 8)); 
	return 0;
}


void Game::close(void)
{
	
	Window::Quit();
}


void Game::handleEvent(void)
{
	SDL_Event e;
	while (SDL_PollEvent(&e)){

		if (e.type == SDL_QUIT)
			this->quit();
		if (e.type == SDL_KEYDOWN){
			switch (e.key.keysym.sym){
			case SDLK_ESCAPE:
				this->quit();
				break;
			default:
				break;
			}
		}
	}

}


