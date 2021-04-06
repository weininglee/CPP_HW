#include "PrimeNumber.h"

int PrimeNumber::get()
{
	return value;
}

PrimeNumber::PrimeNumber() 
{
	value = 1;
}

PrimeNumber::PrimeNumber(int _value)
{
	value = _value;
}

PrimeNumber PrimeNumber::operator++(int) 
{
	PrimeNumber n(value);
	if (value == 1) {
		this->value = 2;
		return n;
	}
	if (value == 2) {
		this->value = 3;
		return n;
	}
	bool isPrime = false;
	while (!isPrime) {
		value++;
		for (int i = 2; i <= value; i++) {
			if (i == value)
			{
				isPrime = true;
				break;
			}
			if (value % i == 0) {
				break;
			}
		}
	}
	this->value = value;
	return n;
}

PrimeNumber& PrimeNumber::operator++() 
{
	if (value == 1) {
		this->value = 2;
		return *this;
	}
	if (value == 2) {
		this->value = 3;
		return *this;
	}
	bool isPrime = false;
	while (!isPrime) {
		value++;
		for (int i = 2; i <= value; i++) {
			if (i == value)
			{
				isPrime = true;
				break;
			}
			if (value % i == 0) {
				break;
			}
		}
	}
	this->value = value;
	return *this;
}

PrimeNumber PrimeNumber::operator--(int) 
{
	PrimeNumber n(value);
	if (value == 1) {
		this->value = 1;
		return n;
	}
	if (value == 2) {
		this->value = 1;
		return n;
	}
	bool isPrime = false;
	while (!isPrime) {
		value--;
		for (int i = 2; i <= value; i++) {
			if (i == value)
			{
				isPrime = true;
				break;
			}
			if (value % i == 0) {
				break;
			}
		}
	}
	this->value = value;
	return n;
}

PrimeNumber& PrimeNumber::operator--() 
{
	if (value == 1) {
		this->value = 1;
		return *this;
	}
	if (value == 2) {
		this->value = 1;
		return *this;
	}
	bool isPrime = false;
	while (!isPrime) {
		value--;
		for (int i = 2; i <= value; i++) {
			if (i == value)
			{
				isPrime = true;
				break;
			}
			if (value % i == 0) {
				break;
			}
		}
	}
	this->value = value;
	return *this;
}
/*
PrimeNumber PrimeNumber::operator=(PrimeNumber n)
{
	value = n.value;
	return n;
}
*/