#ifndef NPC_H_
#define NPC_H_

#include "SDL2includes.h"
#include "Sprite.h"
#include "Player.h"
#include "Bullet.h"

class Game;
class Vector2f;
class Animation;

class NPC : public Sprite
{
private:
	bool isMoving;
	float minRange = 300.0f;
	float maxRange = 100.0f;
	float shotCountdown;

	int dmg;
	
	//Sprite Info
	static const int SPRITE_W = 32;
	static const int SPRITE_H = 32;
	static const int animFrames = 8;
	
	
	Game* game;

public: 
	NPC();
	~NPC();

	void init(SDL_Renderer* ren);
	
	
	void ai();
	

	bool getMoveStatus();
	void fire();
	void setGame(Game* game);
	void update(float dt);
	int getDamage();

};

#endif