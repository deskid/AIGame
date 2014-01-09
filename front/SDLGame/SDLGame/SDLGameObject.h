#pragma once
#include "gameobject.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Vector2D.h"

class SDLGameObject :
	public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
protected:
	Vector2D pos;
	Vector2D v; //velocity
	Vector2D a; //acceleration

	int width;
	int xOffset;
	int height;

	int currentRow;
	int currentFrame;

	std::string textureID;

};

