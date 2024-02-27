#include "SDL2includes.h"
#include "Animation.h"
#include "Player.h"
#include "TextureUtil.h"
#include "Game.h"













const int SDL_OK = 0;


int main(int argc, char* args[])
{
	
	

	int sdl_status = SDL_Init(SDL_INIT_EVERYTHING);
	if (sdl_status != SDL_OK)
	{
		
		printf("Error - SDL Initialisation Failed\n");
		exit(1);
	}
	Game *game = new Game();

	game->init();
	game->runGameLoop();
	delete game;

	
	SDL_Quit();
	exit(0);

}










