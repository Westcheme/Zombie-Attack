#pragma once

#include "ofMain.h"

#include "circle.h"

class Enemy : public Circle
{
public:

	int health;

	ofColor enemyColor;

	string isAlive;

	float theta;

	float xDistance;
	float yDistance;
	float magnitude;
	int speed;

	void setup();
	void update();
	void draw();

	void takeDamage();


	bool hits(Circle other);

	void seek(Circle other);
};