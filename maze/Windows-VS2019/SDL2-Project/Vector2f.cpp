#include "Vector2f.h"

Vector2f::Vector2f()
{
	zero();
}

Vector2f::Vector2f(float x, float y)
{
	setX(x);
	setY(y);
}

Vector2f::Vector2f(Vector2f* other)
{
	x = other->x;
	y = other->y;
}

Vector2f::~Vector2f()
{
	
}

void Vector2f::setX(float x)
{
	this->x = x;
}
float Vector2f::getX(void)
{
	return x;
}
void Vector2f::setY(float y)
{
	this->y = y;
}
float Vector2f::getY(void)
{
	return y;
}

void Vector2f::add(Vector2f* other)
{
	x += other->getX();
	y += other->getY();
}
void Vector2f::sub(Vector2f* other)
{
	x -= other->getX();
	y -= other->getY();

}

void Vector2f::scale(float scale)
{
	x *= scale;
	y *= scale;
}

void Vector2f::zero()
{
	y = x = 0.0f;
}

void Vector2f::normalise()
{
	float len = length();
	if (len > 1.0f)
	{
		x /= len;
		y /= len;
	}
}

float Vector2f::length()
{
	return sqrtf((x * x) + (y * y));
}