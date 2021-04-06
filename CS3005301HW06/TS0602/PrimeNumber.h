#pragma once
#include <iostream>
using namespace std;

class PrimeNumber {
public:
	int value = 1;
	int get();
	PrimeNumber();
	PrimeNumber(int _value);
	PrimeNumber & operator++();
	PrimeNumber operator++(int);
	PrimeNumber & operator--();
	PrimeNumber operator--(int);
	//PrimeNumber operator=(PrimeNumber n);
};