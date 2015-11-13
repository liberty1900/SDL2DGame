#pragma once
#include "SDL.h"
#include "SDL_image.h"
class Game
{
public:
	Game(void);
	bool init(const char* title,int x,int y,int w,int h,Uint32 flags);
	void clean();
	void render();
	void handleEvents();
	void update();
	bool isRunning();
	~Game(void);
private:
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	SDL_Texture* pTexture;
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	bool running;
};
