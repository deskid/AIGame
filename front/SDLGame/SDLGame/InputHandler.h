#pragma once
#include <SDL.h>
#include "Game.h"
#include "Vector2D.h"
#include <vector>
enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:

	static InputHandler* Instance()
	{
		if(pInstance == nullptr)
		{
			pInstance = new InputHandler();
			return pInstance;

		}
		return pInstance;
	}

	bool getMouseButtonState(int buttonNumber)
	{
		return mouseButtonStates[buttonNumber];
	}

	Vector2D getMousePos()
	{
		return mousePos;
	}
	void update(void);
	void clean(void);
private:
	InputHandler(void):mousePos(0,0)
	{
		//0 for left button
		//1 for middle button
		//2 for right button
		for(int i = 0;i <3;i++)
		{
			mouseButtonStates.push_back(false);
		}
	};
	~InputHandler(void){};
	static InputHandler* pInstance;
	std::vector<bool> mouseButtonStates;
	Vector2D mousePos;
};

