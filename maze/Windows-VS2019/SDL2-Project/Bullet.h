#ifndef BULLET_H_
#define BULLET_H_

#include "SDL2includes.h"
#include"Sprite.h"

class Vector2f;
class Animation;
class Game;

class Bullet : public Sprite
{
private:
	bool isMoving;
	static const int SPRITE_W = 32;
	static const int SPRITE_H = 32;
	

	int dmg;
	float lifeTime;

	float angle;
	

public:

	Bullet();
	~Bullet();

	void init(SDL_Renderer* renderer, Vector2f* position, Vector2f* direction);
	void update(float timeDeltaInSeconds);
	void draw(SDL_Renderer* renderer);
	float calculateAngle(Vector2f* direction);

	

	int getDamage();
	bool outOfTime();

	bool getMoveStatus();
};

#endif