#include "bullet.h"

void Bullet::setup()
{
	bullet.load("bullet.png");
	reloadSound.load("reload.mp3");
	firedSound.load("fired.mp3");

	numBullets = 6;

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
	//Ammo Counter
	for (int i = 0; i < numBullets; i++)
	{
		ofSetColor(255, 255, 255);
		bullet.draw(850, 50 + 50 * i, 200, 100);
	}

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
	numBullets = numBullets - 1;

	if (numBullets >= 0)
	{
		firedSound.play();

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

void Bullet::reload()
{
	if (numBullets <= 0)
	{
		reloadSound.play();
		numBullets = 6;
	}
}

void Bullet::bulletStop()
{
	x = 50000;
	y = 50000;
	speed = 0;
	isFired = 0;
}