#include "NPC.h"
#include "TextureUtil.h"
#include "Animation.h"
#include "Vector2f.h"
#include "Game.h"
#include "Bullet.h"
#include "AABB.h"


NPC::NPC() : Sprite()
{
	isMoving = true;
	speed = 25.0f;
	shotCountdown = 10.0f;
	dmg = 3;

	targetRect.w = SPRITE_W * 2;
	targetRect.h = SPRITE_H * 2; //increasing to a more reasonable size
}

NPC::~NPC()
{
	
}

void NPC::init(SDL_Renderer* ren)
{
	string path("assets/images/geraldineflash.png");

	Vector2f position(300.0f, 900.0f);

	Sprite::init(ren, path, &position);

	 

	anim->init(animFrames, SPRITE_W, SPRITE_H, 2);

	aabb = new AABB(this->getPosition(), SPRITE_H, SPRITE_W);


}

void NPC::setGame(Game* game)
{
	this->game = game;
}


bool NPC::getMoveStatus()
{
	return isMoving;
}

void NPC::ai()
{
	Player* player = game->getPlayer();

	Vector2f vectorToPlayer(player->getPosition());

	vectorToPlayer.sub(position);

	float distance = vectorToPlayer.length();

	velocity->setX(vectorToPlayer.getX());
	velocity->setY(vectorToPlayer.getY());
	velocity->normalise();
	velocity->scale(speed);

	if (distance < minRange)
	{

		
		
		if(distance < maxRange)
		{
			velocity->scale(1.5);
		}
		else
			velocity->scale(-1);

		

	}
	else
	{
		

	
		
		if (shotCountdown < 0)
		{
			fire();
			
		}
		
	}
	
	
	
}


void NPC::update(float dt )
{
	ai();
	Sprite::update(dt);
	shotCountdown -= dt;
}



void NPC::fire()
{
		game->createBullet(position, velocity);

	shotCountdown = 10.0f;
	
}

int NPC::getDamage()
{
	return dmg;
}

