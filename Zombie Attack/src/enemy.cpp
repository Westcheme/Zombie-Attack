#include "enemy.h"

void Enemy::setup()
{
	x = 20 + rand() % 980;
	y = 20 + rand() % 980;
	r = 20;

	vx = 1 + rand() % 3;
	vy = 1 + rand() % 3;

	enemyColor = 25 + rand() % 41;

	isAlive = 1;
}

void Enemy::update()
{
	x = vx + x;
	y = vy + y;

	if (x > 980) vx = -1 * vx;
	if (x < 20) vx = -1 * vx;
	if (y > 980) vy = -1 * vy;
	if (y < 20) vy = -1 * vy;
}

void Enemy::draw()
{
	if (isAlive == 1)
	{
		ofFill();
		ofSetColor(0, enemyColor, 0);
		ofDrawCircle(x, y, r);
	}
}

void Enemy::dead()
{
	isAlive = 0;
}