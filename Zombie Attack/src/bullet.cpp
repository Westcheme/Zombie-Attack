#include "bullet.h"

void Bullet::setup()
{
	r = 5;
	vy = 0;

	isFired = 0;
}

void Bullet::update()
{
	x = x + vx;
	y = y - vy;
}

void Bullet::draw()
{
	if (isFired == 1)
	{
		ofSetColor(0, 0, 0);
		ofFill();
		ofDrawCircle(x, y, r);
	}
}

void Bullet::fired(Circle other)
{	
	isFired = 1;

	vy = 20;

	x = other.x;
	y = other.y;
}