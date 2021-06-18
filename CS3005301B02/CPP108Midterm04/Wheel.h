#ifndef Wheel_H 
#define Wheel_H

#include "Cylinder.h"

class Wheel : public Cylinder
{
private:
	Cylinder tire; 
	Cylinder axle; 

public:
	Wheel() : tire(), axle() {}

	void inputWheel() {
		tire.inputCylinder();
		axle.inputCylinder();
	}

	double getVolume() {
		return tire.getVolume() * 2 + axle.getVolume();
	}
};

#endif // Wheel_H 