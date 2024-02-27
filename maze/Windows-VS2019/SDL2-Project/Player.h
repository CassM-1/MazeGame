#ifndef PLAYER_H_
#define PLAYER_H_

#include "SDL2includes.h"
#include "Sprite.h"

class Vector2f;
class Animation; 


class Player : public Sprite
{
private:
	bool isMoving;

	//Sprite Info
	static const int SPRITE_W = 32;
	static const int SPRITE_H = 32;
	static const int animFrames = 16;

	int health = 3;
	//Animation info

	

public:

	Player();
	~Player();

	void processInput(const Uint8* keyStates);
	void init(SDL_Renderer* ren);

	bool getMoveStatus();
	
	void takeDamage(int damage);

	bool isDead();


};
#endif
