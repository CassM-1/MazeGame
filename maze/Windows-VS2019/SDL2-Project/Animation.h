#pragma once
#ifndef ANIMATION_H_
#define ANIMATION_H_
#include "SDL2includes.h"


class Animation
{
private:
	int maxFrames;
	int currentFrame;
	float frameTimeMax;
	float accumulator;

	SDL_Rect* frames;

public:
	Animation();
	~Animation();

	void init(int noOfFrames, int width, int height, int rows);
	SDL_Rect* getCurrentFrame();
	void update(float timeDeltaInSeconds, bool isMoving);


};




#endif