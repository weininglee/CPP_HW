#ifndef Cylinder_H 
#define Cylinder_H

#include "Circle.h"

class Cylinder : public Circle
{
private:
	double width;
	Circle circle;

public:
	Cylinder() : width(0), circle() {}

	void inputCylinder() {
		circle.inputCircle();
		cin >> width;
	}

	double getVolume() {
		return circle.getArea() * width;
	}
};

#endif // Cylinder_H 