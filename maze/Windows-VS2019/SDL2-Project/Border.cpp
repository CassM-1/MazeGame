#include "Border.h"
#include "NPC.h"
#include "TextureUtil.h"
#include "Animation.h"
#include "Vector2f.h"
#include "Game.h"
#include "AABB.h"


//Border is WIP
Border::Border() : Sprite()
{

}
Border::~Border()
{

}

void Border::init(SDL_Renderer* ren)
{
	string path("assets/images/backbad.png");
	

	Vector2f position(600.0f, 600.0f);

	Sprite::init(ren, path, &position);

	aabb = new AABB(this->getPosition(), SPRITE_H, SPRITE_W);
	anim->init(4, SPRITE_W, SPRITE_H, 1);

}

void Border::draw(SDL_Renderer* ren)
{
	Animation* current = this->anim;
	SDL_RenderCopyEx(ren, texture, current->getCurrentFrame(), &targetRect, angle, nullptr, SDL_FLIP_NONE);
}
bool Border::getMoveStatus()
{
	return false;
}