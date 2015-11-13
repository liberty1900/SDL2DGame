#include "Game.h"


Game::Game(void)
{
	pWindow=NULL;
	pRenderer=NULL;
	pTexture=NULL;
	running=true;
	srcRect.x=srcRect.y=0;
	dstRect.x=dstRect.y=0;
}


Game::~Game(void)
{
}

bool Game::init(const char* title,int x,int y,int w,int h,Uint32 flags){
	if(SDL_Init(SDL_INIT_EVERYTHING)==0){
		pWindow=SDL_CreateWindow(title,x,y,w,h,flags);
		//必须使用SDL2_image-2.0.0中的各种dll
		SDL_Surface* pSurface=IMG_Load("images/sprite.png");
		pRenderer=SDL_CreateRenderer(pWindow,-1,0);
		pTexture=SDL_CreateTextureFromSurface(pRenderer,pSurface);
		SDL_FreeSurface(pSurface);
		dstRect.w=srcRect.w=100;
		dstRect.h=srcRect.h=150;
		dstRect.x=(900-dstRect.w)/2;
		dstRect.y=(675-dstRect.h)/2;
		return true;
	}else{
		return false;
	}
}
bool Game::isRunning(){
	return running;
}
void Game::handleEvents(){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				running=false;
				break;
			default:
				break;
		}
	}
}

void Game::update(){
	if(srcRect.x!=300){
		srcRect.x+=100;
	}else{
		srcRect.x=0;
	}
}

void Game::clean(){
	SDL_DestroyTexture(pTexture);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
}
void Game::render(){
	SDL_SetRenderDrawColor(pRenderer,0,80,0,255);
	SDL_RenderClear(pRenderer);//clear the window to red
	SDL_RenderCopy(pRenderer,pTexture,&srcRect,&dstRect);//using the renderer to draw the texture
	SDL_RenderPresent(pRenderer);
}
