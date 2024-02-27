#ifndef GAME_H_
#define GAME_H_

#include "SDL2includes.h"
#include "Player.h"
#include "NPC.h"
#include "Border.h"
#include <vector>
using std::vector;

//Game- main controller class
//Somewhat oversized
//Might be worth breaking into two parts at later date

class Game
{
private:

	SDL_Window* mainWindow = nullptr;
	SDL_Renderer* gameRenderer = nullptr;

	SDL_Texture* backgroundTexture = nullptr;
	NPC* npc;
	Player* player;
	Border* testborder;
	
	bool quit = false;
	
	//current (test) level, player + NPC firing bullets

	vector<Bullet*> bullets;
	const Uint8* keyStates;
	int points;
	int ppf;

	void processInputs();
	void update(float timeDeltaInSeconds);
	void draw();
	
	
	

public:

	static const int WINDOW_W = 1000;
	static const int WINDOW_H = 800;


	Game();
	~Game();

	void init();
	void runGameLoop();
	void createBullet(Vector2f* position, Vector2f* velocity);
	
	Player* getPlayer();


};


#endif