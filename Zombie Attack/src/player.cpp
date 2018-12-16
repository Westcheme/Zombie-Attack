#include "player.h"

void Player::setup()
{
	x = 500;
	y = 500;

	r = 25;

	scoreFont.load("bloody.otf", 60);

	playerColor.set(0, 0, 255);

	health = 100;

	score = 0;
}

void Player::update()
{
	if (health <= 0) health = 0;

	theta = atan2(ofGetMouseY() - y, ofGetMouseX() - x) * 180 / PI;
}

void Player::draw()
{
	//Player

	ofPushMatrix();

	ofTranslate(x, y);

	ofRotate(theta);

	ofFill();
	ofSetColor(playerColor);
	ofDrawCircle(0, 0, r);

	ofNoFill();
	ofSetLineWidth(3);
	ofSetColor(0, 0, 0);
	ofDrawCircle(0, 0, r);

	ofFill();
	ofSetColor(0, 0, 0);
	ofDrawRectangle(25, -5, 25, 10);

	ofPopMatrix();


	//Player Health Bar
	ofFill();
	if (health <= 100) ofSetColor(0, 255, 0);
	if (health <= 70) ofSetColor(255, 255, 0);
	if (health <= 30) ofSetColor(255, 0, 0);
	ofDrawRectangle(880, 20, health, 40);

	ofNoFill();
	ofSetLineWidth(3);
	ofSetColor(0, 0, 0);
	ofDrawRectangle(880, 20, 100, 40);

	//Player Score
	scoreFont.drawString(to_string(score), 780, 60);
}

void Player::up()
{
	y = y - 10;
}

void Player::down()
{
	y = y + 10;
}

void Player::left()
{
	x = x - 10;
}

void Player::right()
{
	x = x + 10;
}