#include "Bullet.h"


#include "NPC.h"
#include "TextureUtil.h"
#include "Animation.h"
#include "Vector2f.h"
#include "Game.h"
#include "AABB.h"


Bullet::Bullet() : Sprite()
{
	isMoving = true;
	speed = 150.0f;

	angle = 0.0f;
	dmg = 1;
	lifeTime = 20.0f;
	
	
	targetRect.w = SPRITE_W * 2;
	targetRect.h = SPRITE_H * 2; //increasing to a more reasonable size
}

Bullet::~Bullet() 
{

}

void Bullet::init(SDL_Renderer* ren, Vector2f* position, Vector2f* direction)
{
	this->angle = calculateAngle(direction);

	string path("assets/images/shot.png");

	Sprite::init(ren, path, position);
	velocity->setX(direction->getX());
	velocity->setY(direction->getY());
	velocity->normalise();
	velocity->scale(speed);
	anim->init(4,SPRITE_W, SPRITE_H, 1);

	aabb = new AABB(this->getPosition(), SPRITE_H, SPRITE_W);

}

float Bullet::calculateAngle(Vector2f* direction)
{
	float ang = atan2f(direction->getY(), direction->getX());
	ang *= (180.0f / 3.142f);
	return ang;
}
void Bullet::update(float deltaTime)
{
	lifeTime -= deltaTime;
	Sprite::update(deltaTime);
}

void Bullet::draw(SDL_Renderer* ren)
{
	Animation* current = this->anim;

	SDL_RenderCopyEx(ren, texture, current->getCurrentFrame(), &targetRect, angle, nullptr, SDL_FLIP_NONE);

}
int Bullet::getDamage()
{
	return dmg;
}

bool Bullet::outOfTime()
{
	if (lifeTime > 0.0f)
		return false;
	else
		return true;
}

bool Bullet::getMoveStatus()
{
	return isMoving;
}