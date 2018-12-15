#include "enemy.h"

void Enemy::setup()
{
	isAlive = "alive";

	x = 25 + rand() % 950;
	y = 1050;
	r = 20;

	health = 15;

	enemyColor.set(0, 25 + rand() % 41, 0);

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

		ofPushMatrix();

		ofTranslate(x, y);

		ofRotate(-theta);

		ofFill();
		ofSetColor(enemyColor);
		ofDrawCircle(0, 0, r);

		ofFill();
		ofSetColor(enemyColor);
		ofDrawRectangle(-20, 0, 5, 30);

		ofFill();
		ofSetColor(enemyColor);
		ofDrawRectangle(15, 0, 5, 30);

		ofPopMatrix();


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

		theta = atan2(xDistance, yDistance) * 180 / PI;

		magnitude = sqrt(xDistance * xDistance + yDistance * yDistance);

		xDistance = xDistance / magnitude;
		yDistance = yDistance / magnitude;

		x = x + xDistance * speed;
		y = y + yDistance * speed;
	}
}