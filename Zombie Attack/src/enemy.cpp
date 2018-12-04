#include "enemy.h"

void Enemy::setup()
{
	isAlive = "alive";

	x = 25 + rand() % 950;
	y = 25;
	r = 20;

	health = 15;

	enemyColor = 25 + rand() % 41;

	speed = 1;
}

void Enemy::update()
{
	
}

void Enemy::draw()
{
	if (isAlive == "alive")
	{
		//Enemy
		ofFill();
		ofSetColor(0, enemyColor, 0);
		ofDrawCircle(x, y, r);

		ofFill();
		ofSetColor(0, enemyColor, 0);
		ofDrawRectangle(x - 20, y, 5, 30);

		ofFill();
		ofSetColor(0, enemyColor, 0);
		ofDrawRectangle(x + 15, y, 5, 30);


		//Enemy Health
		ofFill();
		if (health <= 100) ofSetColor(0, 255, 0);
		if (health <= 70) ofSetColor(255, 255, 0);
		if (health <= 30) ofSetColor(255, 0, 0);
		ofDrawRectangle(x - 8, y - 30, health, 5);

		ofNoFill();
		ofSetLineWidth(3);
		ofSetColor(0, 0, 0);
		ofDrawRectangle(x - 8, y - 30, 15, 5);
	}
}

void Enemy::takeDamage()
{
	health = health - 5;

	if (health <= 0) isAlive = "dead";
}

bool Enemy::hits(Circle other)
{
	if (isAlive == "alive")
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

void Enemy::seek(Circle other)
{
	if (isAlive == "alive")
	{
		xDistance = other.x - x;
		yDistance = other.y - y;

		magnitude = sqrt(xDistance * xDistance + yDistance * yDistance);

		xDistance = xDistance / magnitude;
		yDistance = yDistance / magnitude;

		x = x + xDistance * speed;
		y = y + yDistance * speed;
	}
}