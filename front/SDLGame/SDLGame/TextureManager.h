#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <string>
#include <iostream>
#include <SDL.h>
#include <map>
#include "window.h"

class TextureManager
{
private: 
	std::map<std::string ,SDL_Texture*> textureMap;
	TextureManager(void) {};
	static TextureManager* pInstance;
public:
	static TextureManager* Instance()
	{
		if(pInstance == nullptr)
		{
			pInstance = new TextureManager();
			return pInstance;
		}
		return pInstance;
	};
	~TextureManager(void);

	/**
	*  load a img as the texture and store it into the map with id
	*  @param fileName image file path and file name 
	*  @param id The index id in the map
	*/
	bool load(std::string fileName, std::string id);



	/**
	*  Draw a SDL_Texture to the screen at the point(x,y) as lefttop with width and height
	*  @param id The SDL_Texture' index to draw
	*  @param x The disRect.x
	*  @param y The disRect.y
	*  @param width The texture width
	*  @param height The texture height
	*  @param flip The flip to apply to the image, default is none
	*/
	void draw(std::string id,int x ,int y ,int width, int height,SDL_RendererFlip flip = SDL_FLIP_NONE);



	/**
	*  Draw a frame of SDL_Texture to the screen at the point(x,y) as lefttop with width and height
	*  @param id The SDL_Texture' index to draw
	*  @param x The disRect.x
	*  @param y The disRect.y
	*  @param width The texture width
	*  @param xOffset The x offset of each frame 
	*  @param height The texture height //there we can ensure that the spirt will only hava 1 row 
	*  @param currentRow The row of texture in the spirit
	*  @param currentFrame The frame of texture in the spirit
	*  @param flip The flip to apply to the image, default is none
	*/
	void drawFrame(std::string id,int x,int y,int width,int xOffset, int height,int currentRow ,int currentFrame,SDL_RendererFlip flip = SDL_FLIP_NONE);

};

#endif