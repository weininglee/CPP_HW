#include "Point.h"

void Point::Set(int vertical, int horizontal)
{
	this->vertical = vertical;
	this->horizontal = horizontal;
}

void Point::Move(int x, int y)
{
	vertical += x;
	horizontal += y;
}
void Point::Rotate()
{
	int temp = 0;
	temp = vertical;
	vertical = horizontal;
	horizontal = (-1) * temp;
}
