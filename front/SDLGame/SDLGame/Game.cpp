#include "Game.h"
#include "SDLGameObject.h"
#include <iostream>

Game* Game::pInstance = nullptr;

void Game::init(void)
{
	try {
		Window::Init("AI Magic Land");
		TextureManager::Instance()->load("resource/pics/fire.png","fire");

		GameObject* fire_live = new SDLGameObject(new LoaderParams(300,200,72,50,72,"fire"));
		vGameObjects.push_back(fire_live);

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

	for(auto i : vGameObjects)
	{
		i->draw();
	}
	//TextureManager::Instance()->draw("fire",200,200,72,72);
	//TextureManager::Instance()->drawFrame("fire",300,200,72,50,72,1,currentFrame);

	Window::Present();
}


int Game::update(void)
{
	//currentFrame =  int(((SDL_GetTicks() / 100) % 8)); 

	for(auto i : vGameObjects)
	{
		i->update();
	}
	return 0;
}


void Game::close(void)
{

	Window::Quit();
}


void Game::handleEvent(void)
{
	InputHandler::Instance()->update();

}


