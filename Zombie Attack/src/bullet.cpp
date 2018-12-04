#include "bullet.h"

void Bullet::setup()
{
	r = 5;

	isFired = 0;

	speed = 1;
}

void Bullet::update()
{
	if (isFired = 1)
	{
		x = x + xDistance * speed;
		y = y + yDistance * speed;
	}
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
	speed = 20;

	if (isFired == 1)
	{
		x = other.x;
		y = other.y;
	
		xDistance = ofGetMouseX() - x;
		yDistance = ofGetMouseY() - y;

		magnitude = sqrt(xDistance * xDistance + yDistance * yDistance);

		xDistance = xDistance / magnitude;
		yDistance = yDistance / magnitude;
	}
}

bool Bullet::hits(Circle other)
{
	if (isFired == 1)
	{
		float sum, dist;

		bool result;

		sum = (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);

		dist = sqrt(sum);

		if (dist < r + other.r) result = true;
		else result = false;

		return(result);
	}
}

void Bullet::bulletStop()
{
	x = 50000;
	y = 50000;
	speed = 0;
	isFired = 0;
}