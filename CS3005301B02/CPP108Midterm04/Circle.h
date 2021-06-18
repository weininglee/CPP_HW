#ifndef Circle_H 
#define Circle_H

#include <iostream>
using namespace std;
const double PI = 3.14159;

class Circle
{
private:
	double r;
public:
	Circle() : r(0) {}

	void inputCircle() {
		cin >> r;
	}

	double getArea() {
		return r * r * PI;
	}
};

#endif // Circle_H 