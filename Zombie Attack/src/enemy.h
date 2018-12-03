#pragma once

#include "ofMain.h"

#include "circle.h"

class Enemy : public Circle
{
public:

	int vx, vy;

	int enemyHealth;

	int enemyColor;

	int isAlive;

	void setup();
	void update();
	void draw();

	void dead();
};