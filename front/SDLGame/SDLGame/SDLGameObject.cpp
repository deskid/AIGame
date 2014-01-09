#include "SDLGameObject.h"


SDLGameObject::SDLGameObject(const LoaderParams* pParams):GameObject(pParams),pos(pParams->getX(),pParams->getY()),v(0,0),a(0,0)
{

	width = pParams->getWidth();
	xOffset = pParams->getXOffset();
	height = pParams->getHeight();

	textureID  = pParams->getTextureID();

	currentFrame = 1;
	currentRow = 1;
}


void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(textureID,(int)pos.getX(),(int)pos.getY(),width,xOffset,height,currentRow,currentFrame);
}

void SDLGameObject::update()
{
	Vector2D vec2dTemp = InputHandler::Instance()->getMousePos();
	v = (vec2dTemp - pos)/100;
	v += a;
	pos += v;
	currentFrame =  int(((SDL_GetTicks() / 100) % 8)); 
	// in the specific object , currentframe and accelerate will be update;
}

void SDLGameObject::clean()
{

}