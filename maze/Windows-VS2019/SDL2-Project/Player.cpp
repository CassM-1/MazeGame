#include "Player.h"
#include "TextureUtil.h"
#include "Animation.h"
#include "Vector2f.h"
#include "AABB.h"

Player::Player() : Sprite()
{
	isMoving = false;
	speed = 100.0f;
	int health = 3;

	targetRect.w = SPRITE_W * 2;
	targetRect.h = SPRITE_H * 2; //increasing to a more reasonable size
}


Player::~Player()
{

	
}

void Player::init(SDL_Renderer* ren)
{
	string path("assets/images/stickmove.png");

	 Vector2f position(200.0f, 200.0f);
	
	 Sprite::init(ren, path, &position);

	

	


	
	anim->init( animFrames, SPRITE_W,SPRITE_H, 4);

	aabb = new AABB(this->getPosition(), SPRITE_H, SPRITE_W);
}



void Player::processInput( const Uint8 *keyStates)
{

	float yinp = 0.0f;
	float xinp = 0.0f;
	
	isMoving = false;

	if (keyStates[SDL_SCANCODE_UP])
	{
		yinp = -1.0f;
		angle = 0;
		isMoving = true;
	}
	if (keyStates[SDL_SCANCODE_DOWN])
	{
		yinp = 1.0f;
		angle = 180;
		isMoving = true;
	}
	if (keyStates[SDL_SCANCODE_RIGHT])
	{
		xinp = 1.0f;
		angle = 90;
		isMoving = true;
	}
	if (keyStates[SDL_SCANCODE_LEFT])
	{
		xinp = -1.0f;
		angle = 270;
		isMoving = true;
	}


	velocity->setX(yinp);
	velocity->setY(xinp);//invert
	velocity->normalise();
	velocity->scale(speed);
}

bool Player::getMoveStatus()
{
	return isMoving;
}
void Player::takeDamage(int damage)
{
	health -= damage;
}
bool Player::isDead()
{
	if (health <= 0)
		return true;
	else
		return false;
}