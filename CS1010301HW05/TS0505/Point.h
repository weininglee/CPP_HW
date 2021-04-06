#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
	double horizontal;
	double vertical;

public:
	Point() {
		horizontal = 0;
		vertical = 0;
	}
	~Point();
	void Set(double horizontal, double vertical);
	void Move(double x, double y);
	void Rotate();
	void Reflect();
	double GetVertical() const { return vertical; }
	double GetHorizontal() const { return horizontal; }
};

