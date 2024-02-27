#include "TextureUtil.h"

SDL_Texture* createTexture(SDL_Renderer* Rend, const char* fileName)
{

	SDL_Texture* texture = nullptr;
	SDL_Surface* temp = nullptr;

	temp = IMG_Load(fileName);
	if (temp == nullptr)
	{
		printf("%s file not found", fileName);

	}
	else
	{
		texture = SDL_CreateTextureFromSurface(Rend, temp);
		SDL_FreeSurface(temp);
		temp = nullptr;

	}
	return texture;
}