#ifndef VECTOR2F_H_
#define VECTOR2F_H_

#include "SDL2includes.h"


class Vector2f
{
private:
	float x;
	float y;

public:
	
	//various constructors
	Vector2f();
	Vector2f(float x, float y);
	Vector2f(Vector2f* other);

	//destructor
	~Vector2f();

	//functions
	void zero();
	void normalise();
	float length();

	void setX(float x);
	float getX(void);

	void setY(float y);
	float getY(void);

	void add(Vector2f* other);
	void sub(Vector2f* other);

	void scale(float scale);


};


#endif

