#pragma once

#include "SDL2includes.h"
#include "Sprite.h"

//border is WIP
class Vector2f;
class Animation;
class Game;

class Border :	public Sprite
{
private: 
	static const int SPRITE_W = 32;
	static const int SPRITE_H = 32;

public:
	Border();
	~Border();

	void init(SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer);
	bool getMoveStatus();
};

