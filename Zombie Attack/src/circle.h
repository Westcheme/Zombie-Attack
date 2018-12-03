#pragma once

#include "ofMain.h"

class Circle
{
public:

	float x;
	float y;
	float r;

	Circle();
	Circle(float x_in, float y_in, float r_in);

	bool Circle::intersects(Circle other);
};