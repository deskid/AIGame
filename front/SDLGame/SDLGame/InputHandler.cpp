#include "InputHandler.h"
InputHandler* InputHandler::pInstance = nullptr;

void InputHandler::update(void)
{
	SDL_Event e;
	while (SDL_PollEvent(&e)){

		if (e.type == SDL_QUIT)
			Game::Instance()->quit();
		if (e.type == SDL_KEYDOWN){
			switch (e.key.keysym.sym){
			case SDLK_ESCAPE:
				Game::Instance()->quit();
				break;
			default:
				break;
			}
		}
		// mouse event
		if(e.type == SDL_MOUSEBUTTONDOWN)
		{
			if(e.button.button == SDL_BUTTON_LEFT)
			{
				mouseButtonStates[LEFT] = true;
			}
			if(e.button.button == SDL_BUTTON_MIDDLE)
			{
				mouseButtonStates[MIDDLE] = true;
			}
			if(e.button.button == SDL_BUTTON_RIGHT)
			{
				mouseButtonStates[RIGHT] = true;
			}
		}
		if(e.type == SDL_MOUSEBUTTONUP)
		{
			if(e.button.button == SDL_BUTTON_LEFT)
			{
				mouseButtonStates[LEFT] = false;
			}
			if(e.button.button == SDL_BUTTON_MIDDLE)
			{
				mouseButtonStates[MIDDLE] = false;
			}
			if(e.button.button == SDL_BUTTON_RIGHT)
			{
				mouseButtonStates[RIGHT] = false;
			}
		}
		if(e.type == SDL_MOUSEMOTION)
		{
			mousePos.setX(e.motion.x);
			mousePos.setY(e.motion.y);
		}
	}
}


void InputHandler::clean(void)
{
}
