#pragma once
#include <string>
#include <iostream>
#include <SDL.h>

class LoaderParams;
class GameObject
{
public:

	virtual void draw(void) = 0;
	virtual void update(void) = 0;
	virtual void clean(void) = 0;

protected:
	GameObject(const LoaderParams* pParams){}
	virtual ~GameObject(){}
};



/**
*  object init options 
*  @param x The object's x in the screen
*  @param y The object's y in the screen
*  @param width The object's texture's width
*  @param xOffset The object's texture's x's offset in spirit
*  @param height The object's texture's height
*  @param ID The object's texture's ID
*/
class LoaderParams
{
public:
	LoaderParams(int _x, int _y, int _width,int _xOffset, int _height, std::string
		_textureID) : x(_x), y(_y), width(_width),xOffset(_xOffset), height(_height),
		textureID(_textureID)
	{
	}
	int getX() const { return x; }
	int getY() const { return y; }
	int getWidth() const { return width; }
	int getXOffset() const { return xOffset; }
	int getHeight() const { return height; }
	std::string getTextureID() const { return textureID; }
private:
	int x;
	int y;
	int width;
	int xOffset;
	int height;
	std::string textureID;
};