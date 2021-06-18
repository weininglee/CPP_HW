#ifndef Car_H 
#define Car_H 
#include "Wheel.h"

class Car
{
private:
	double length;
	double width;
	double height;
	int wheelN;
	Wheel wheel;

public:
	Car() : length(0), width(0), height(0), wheelN(0), wheel() {}

	void inputCar() {
		cin >> length >> width >> height >> wheelN;
		wheel.inputWheel();
	}

	double getVolume() {
		return wheel.getVolume() * wheelN + length * width * height;
	}
};

#endif // Car_H 