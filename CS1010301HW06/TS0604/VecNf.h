#pragma once
#include <iostream>
#include <vector>
using namespace std;

class VecNf
{
public:
	float* vStart = 0;
	int count = 0;

	VecNf();
	VecNf(float* dest, int cnt);
	VecNf(const VecNf& rhs);
	~VecNf();

	int Size();
	float& operator[](int i);
	VecNf operator+(VecNf v);
	VecNf operator-(VecNf v);
	float operator*(VecNf v);
	friend VecNf operator*(float multi, VecNf v);
	friend VecNf operator*(VecNf v, float multi);
	VecNf& operator=(VecNf v);
	friend ostream& operator<<(ostream& out, VecNf v);
};
