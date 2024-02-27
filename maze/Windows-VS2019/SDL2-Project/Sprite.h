#ifndef SPRITE_H_
#define SPRITE_H_

#include "SDL2includes.h"

#include <string>
using std::string;

class Vector2f;
class Animation;
class AABB;

class Sprite
{
protected:
	//texture that stores sprite sheet
	SDL_Texture* texture;


	//player information

	SDL_Rect targetRect;




	float speed;
	Vector2f* position;
	Vector2f* velocity;
	float angle;

	Animation* anim;
	AABB* aabb;

public:
	Sprite();
	virtual ~Sprite();

	virtual void init(SDL_Renderer* ren, string textureFileName, Vector2f* position);

	virtual void draw(SDL_Renderer* gameRenderer);
	
	virtual void update(float timeDeltaInSeconds);

	virtual bool getMoveStatus() = 0;

	Vector2f* getPosition();
	AABB* getAABB();
};




#endif