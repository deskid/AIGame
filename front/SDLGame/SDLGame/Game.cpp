#include "Game.h"
#include <iostream>

void Game::init(void)
{
	try {
		Window::Init("AI Magic Land");
	}
	catch (const std::runtime_error &e){
		std::cout << e.what() << std::endl;
		Window::Quit();

	}
}

void Game::loadMedia(void)
{

	try {
		//Load the image
		std::string imgFile = "resource/pics/fire.png";
		gBackground = Window::LoadImage(imgFile);

		pos.w = 72;
		pos.h = 72;
		pos.x = 0;
		pos.y = 0;

		//Load the font and message
		//std::string fontFile = "resource/ttf/Monaco.ttf";
		//std::string text = "TTF Fonts too!";
		//SDL_Color color = { 255, 255, 255 };
		//msg = Window::RenderText(text, fontFile, color, 100);
	}
	catch (const std::runtime_error &e){
		//Catch error and crash
		std::cout << e.what() << std::endl;
		Window::Quit();

	}
}

void Game::render(void)
{
	//RENDERING
	Window::Clear();

	SDL_Rect dstRect = { Window::Box().w / 2 - 36 / 2,Window::Box().h / 2 - 36 / 2, 72, 72 };
	Window::Draw(gBackground, pos,dstRect);
	//Window::Draw(msg, pos);

	Window::Present();
}


int Game::updata(void)
{
	pos.x =  (72+50) * int(((SDL_GetTicks() / 100) % 8)); 
	return 0;
}


void Game::close(void)
{
	SDL_DestroyTexture(gBackground);
	SDL_DestroyTexture(msg);
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


