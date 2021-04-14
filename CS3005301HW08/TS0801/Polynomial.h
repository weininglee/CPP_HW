#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Polynomial {

public:

	vector<double> param;

	Polynomial();
	Polynomial(double* param, int size);

	int mySize();
	double evaluate(const Polynomial& poly, const double& var);

	Polynomial& operator=(Polynomial v);
	Polynomial operator+(Polynomial v);
	friend Polynomial operator+(double num, Polynomial v);
	Polynomial operator-(Polynomial v);
	friend Polynomial operator-(double num, Polynomial v);
	Polynomial operator*(Polynomial v);
	friend Polynomial operator*(double num, Polynomial v);
	double& operator[](int i);
};