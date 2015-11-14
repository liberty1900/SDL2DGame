#include "TextureManager.h"
#include "SDL_image.h"

TextureManager* TextureManager::pInstance=NULL;

TextureManager* TextureManager::Instance(){
	if(pInstance==NULL){
		pInstance=new TextureManager();
	}
	return pInstance;
}

bool TextureManager::load(std::string filename,std::string id,SDL_Renderer* renderer){
	SDL_Surface* tempSurface=IMG_Load(filename.c_str());//using c_str() to fit the parameter's type
	SDL_Texture* pTexture=SDL_CreateTextureFromSurface(renderer,tempSurface);
	SDL_FreeSurface(tempSurface);
	if(pTexture!=NULL){
		textureMap[id]=pTexture;
		return true;
	}
	return false;
}

void TextureManager::draw(SDL_Renderer* pRenderer,std::string id,int dstX,int dstY,int srcWidth,int srcHeight,SDL_RendererFlip flip){
	SDL_Rect srcRect,dstRect;
	srcRect.x=srcRect.y=0;
	dstRect.h=srcRect.h=srcHeight;
	dstRect.h=srcRect.w=srcWidth;
	dstRect.x=dstX;
	dstRect.y=dstY;
	SDL_RenderCopyEx(pRenderer,textureMap[id],&srcRect,&dstRect,0,0,flip);
}

void TextureManager::drawFrame(SDL_Renderer* pRenderer,std::string id,int currentFrame,int srcWidth,int srcHeight,int dstX,int dstY,SDL_RendererFlip flip){
	SDL_Rect srcRect,dstRect;
	dstRect.x=dstX;
	dstRect.y=dstY;
	srcRect.w=dstRect.w=srcWidth;
	srcRect.h=dstRect.h=srcHeight;
	if(currentFrame%4!=0)
		srcRect.x=(currentFrame%4-1)*srcWidth;
	else
		srcRect.x=3*srcWidth;
	srcRect.y=0;
	SDL_RenderCopyEx(pRenderer,textureMap[id],&srcRect,&dstRect,0,0,flip);
}
