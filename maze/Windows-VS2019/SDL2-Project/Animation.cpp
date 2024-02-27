#include "Animation.h"
#include <stdexcept>
#include "SDL2includes.h"


Animation::Animation()
{
	
		//should be set later
		
		maxFrames = 0;
		frames = nullptr;

		
		frameTimeMax = 0.4f; //2.5 fps
		
		
		currentFrame = 0;
		
		accumulator = 0.0f;

}

Animation::~Animation()
{
	
		delete frames;
		frames = nullptr;

}


void Animation::init(int noOfFrames, int width, int height, int rows)
{
	if (noOfFrames < 1)
	{
		throw std::runtime_error("Bad parameters to init");
			
	}
	maxFrames = noOfFrames;
	frames = new SDL_Rect[maxFrames];
		
		
		
		//setup animation frames, this assumes sprite sheet uses four columns (spritesheets will be made with this in mind)
	int frameAssign = 0;
	for (int x = 0; x < rows; x++)
	{
		for (int i = 0; i < 4; i++)
		{
			frames[frameAssign].x = (i * width);
			frames[frameAssign].y = (x * height);
			frames[frameAssign].w = width;
			frames[frameAssign].h = height;
			frameAssign++;
		}
	}
	
}

SDL_Rect* Animation::getCurrentFrame()
{
	return &frames[currentFrame];
}

void Animation::update(float timeDeltaInSeconds, bool ismoving)
{

	accumulator += timeDeltaInSeconds;

	
	if (accumulator > frameTimeMax)
	{
		if (ismoving)
		{
			currentFrame++;
			accumulator = 0.0f;

			if (currentFrame >= maxFrames)
			{
				currentFrame = 0;
			}
		}
		else
		{
			currentFrame = 4;
		}
	}
}




