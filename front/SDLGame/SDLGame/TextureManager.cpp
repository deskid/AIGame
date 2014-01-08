#include "TextureManager.h"

TextureManager* TextureManager::pInstance = 0;

TextureManager::~TextureManager(void)
{
}


bool TextureManager::load(std::string fileName, std::string id)
{
	try {
		SDL_Texture* pTexture = Window::LoadImage(fileName);
		textureMap[id] = pTexture; //memory leak? shared_ptr?
		return true;
	}
	catch (const std::runtime_error &e){
		//Catch error and crash
		std::cout << e.what() << std::endl;
		Window::Quit();
		return false;

	}
	return false;
}


//
void TextureManager::draw(std::string id,int x ,int y ,int width, int height,SDL_RendererFlip flip )
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	Window::Draw(textureMap[id], srcRect,destRect,0,0,0,flip);
}


void TextureManager::drawFrame(std::string id,int x,int y,int width,int xOffset, int height,int currentRow ,int currentFrame,SDL_RendererFlip flip )
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = (width + xOffset)* currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	Window::Draw(textureMap[id], srcRect,destRect,0,0,0,flip);
}
