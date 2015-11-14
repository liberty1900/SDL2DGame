#include "Game.h"


Game::Game(void)
{
	pWindow=NULL;
	pRenderer=NULL;
	currentFrame=0;
	running=true;
}


Game::~Game(void)
{
}

bool Game::init(const char* title,int x,int y,int w,int h,Uint32 flags){
	if(SDL_Init(SDL_INIT_EVERYTHING)==0){
		pWindow=SDL_CreateWindow(title,x,y,w,h,flags);
		pRenderer=SDL_CreateRenderer(pWindow,-1,0);	
		TextureManager::Instance()->load("images/sprite.png","player",pRenderer);//create texture* textureMap["player"]
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
	currentFrame++;
}

void Game::clean(){
	//SDL_DestroyTexture();
	//SDL_DestroyRenderer(pRenderer);
	//SDL_DestroyWindow(pWindow);
}
void Game::render(){
	SDL_SetRenderDrawColor(pRenderer,0,80,0,255);
	SDL_RenderClear(pRenderer);//clear the window to red
	TextureManager::Instance()->drawFrame(pRenderer,"player",currentFrame,100,150,0,0,SDL_FLIP_NONE);
	SDL_RenderPresent(pRenderer);
}
