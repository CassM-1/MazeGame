
#include "Sprite.h"
#include "Animation.h"
#include "Vector2f.h"
#include "TextureUtil.h"
#include <stdexcept>
#include "AABB.h"

Sprite::Sprite()
{
	speed = 0.0f;

	position = nullptr;
	velocity = nullptr;

	texture = nullptr;

	anim = nullptr;

	aabb = nullptr;
}

Sprite::~Sprite()
{
	delete position;
	position = nullptr;
	delete velocity;
	velocity = nullptr;


	delete  anim;
	anim = nullptr;

	delete aabb;
	aabb = nullptr;

	SDL_DestroyTexture(texture);
	texture = nullptr;
}	

void Sprite::init(SDL_Renderer* ren, string textureFileName, Vector2f* initpos)
{
	 speed;

	position = new Vector2f(initpos);

	
	velocity = new Vector2f();
	velocity->zero();


	texture = createTexture(ren, textureFileName.c_str());
	if (texture == nullptr)
		throw std::runtime_error("file not found");


	anim = new Animation();


	
}

void Sprite::draw(SDL_Renderer* ren)
{
	Animation* current = anim;
	SDL_RenderCopyEx(ren, texture, current->getCurrentFrame(), &targetRect, angle, NULL, SDL_FLIP_NONE);
}

void Sprite::update(float timeDeltaInSeconds)
{

	Vector2f movement(velocity);
	movement.scale(timeDeltaInSeconds);

	position->add(&movement);

	targetRect.y = round(position->getX());
	targetRect.x = round(position->getY());

	Animation* current = anim;
	current->update(timeDeltaInSeconds, getMoveStatus());

	if (aabb != nullptr)
		aabb->setPosition(position);


}

Vector2f* Sprite::getPosition()
{
	return position;
}
AABB* Sprite::getAABB()
{
	return aabb;
}