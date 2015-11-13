#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
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
	TextureManager textureManager;
	int currentFrame;
	bool running;
};

