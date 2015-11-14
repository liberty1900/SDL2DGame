#pragma once
#include <iostream>
#include <string>
#include <Map>
#include "SDL.h"
class TextureManager
{
public:
	static TextureManager* Instance();
	bool load(std::string filename,std::string id,SDL_Renderer* renderer);
	//using renderer to simply draw the original image to the screen 
	void draw(SDL_Renderer* pRenderer,std::string id,int dstX,int dstY,int srcWidth,int srcHeight,SDL_RendererFlip flip);
	//draw a specific part(flame) of the image to the screen
	//SUPPOSING the sprite sheet only has 1 row and 4 frames 
	void drawFrame(SDL_Renderer* pRenderer,std::string id,int currentFlame,int srcWidth,int srcHeight,int dstX,int dstY,SDL_RendererFlip flip);

	~TextureManager(){}
private:
	TextureManager(){}
	static TextureManager* pInstance;
	std::map<std::string,SDL_Texture*> textureMap;
};


