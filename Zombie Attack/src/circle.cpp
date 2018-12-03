#include "circle.h"

Circle::Circle()
{
	x = 0;
	y = 0;
	r = 1;
}

Circle::Circle(float x_in, float y_in, float r_in)
{
	x = x_in;
	y = y_in;
	r = r_in;
}

bool Circle::intersects(Circle other)
{
	float sum, dist;

	bool result;

	sum = (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);

	dist = sqrt(sum);

	if (dist < r + other.r) result = true;
	else result = false;

	return(result);
}