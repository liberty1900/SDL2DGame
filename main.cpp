#include "Game.h"
int main(int argc,char* args[]){
	Game* game=new Game();
	if(game->init("Demo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,900,625,SDL_WINDOW_SHOWN)){
		while(game->isRunning()){
			game->handleEvents();
			game->update();
			game->render();
			SDL_Delay(200);
		}
		game->clean();
		SDL_Quit();
		return 0;
	}
	return 1;
}
