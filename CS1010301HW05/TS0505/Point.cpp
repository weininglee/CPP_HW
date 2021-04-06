#include "Point.h"

void Point::Set(double horizontal, double vertical)
{
	this->vertical = vertical;
	this->horizontal = horizontal;
}

void Point::Move(double x, double y)
{
	horizontal += x;
	vertical += y;
	if (horizontal == -horizontal) {
		horizontal = 0;
	}
	if (vertical == -vertical) {
		vertical = 0;
	}
}
void Point::Rotate()
{
		auto temp = horizontal;
		horizontal = vertical;
		vertical = (-1) * temp;
		if (horizontal == -horizontal) {
			horizontal = 0;
		}
		if (vertical == -vertical) {
			vertical = 0;
		}
}

void Point::Reflect() 
{
	horizontal = (-1) * horizontal;
	vertical = (-1) * vertical;
	if (horizontal == -horizontal) {
		horizontal = 0;
	}
	if (vertical == -vertical) {
		vertical = 0;
	}
}

Point::~Point() {

}