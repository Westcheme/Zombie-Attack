#pragma once

#include "ofMain.h"

#include "circle.h"

class Player : public Circle
{
public:

	ofColor playerColor;

	int health;
	int healthx;
	int healthy;
	int width;
	int height;

	float theta;

	void setup();
	void update();
	void draw();

	void up();
	void down();
	void left();
	void right();
};