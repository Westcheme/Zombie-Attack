#include "player.h"




void Player::setup()
{
	x = 500;
	y = 500;
	r = 25;


	health = 100;

	healthx = 880;
	healthy = 20;
	width = 100;
	height = 40;
}

void Player::update()
{
	if (x > 975) x = 975;
	if (x < 25) x = 25;
	if (y > 975) y = 975;
	if (y < 25) y = 25;

	if (health <= 0) health = 0;
}

void Player::draw()
{
	ofFill();
	ofSetColor(0, 0, 255);
	ofDrawCircle(x, y, r);

	ofNoFill();
	ofSetLineWidth(3);
	ofSetColor(0, 0, 0);
	ofDrawCircle(x, y, r);

	ofFill();
	if (health <= 100) ofSetColor(0, 255, 0);
	if (health <= 70) ofSetColor(255, 255, 0);
	if (health <= 30) ofSetColor(255, 0, 0);
	ofDrawRectangle(healthx, healthy, health, height);

	ofNoFill();
	ofSetLineWidth(3);
	ofSetColor(0, 0, 0);
	ofDrawRectangle(healthx, healthy, width, height);
}

float Player::up()
{
	y = y - 10;
	return(y);
}

float Player::down()
{
	y = y + 10;
	return(y);
}

float Player::left()
{
	x = x - 10;
	return(x);
}

float Player::right()
{
	x = x + 10;
	return(x);
}