#pragma once

#include "ofMain.h"

#include "circle.h"

class Player : public Circle
{
public:

	ofColor playerColor;

	ofTrueTypeFont scoreFont;

	int health;

	int score;

	float theta;

	void setup();
	void update();
	void draw();

	void up();
	void down();
	void left();
	void right();
};