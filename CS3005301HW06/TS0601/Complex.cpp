#include "Complex.h"

Complex::Complex()
{
	realValue = 0;
	imaginaryValue = 0;
}

//~Complex();

Complex::Complex(double r)
{
	realValue = r;
	imaginaryValue = 0;
}

//~Complex(double r);

Complex::Complex(double r, double i)
{
	realValue = r;
	imaginaryValue = i;
}

//~Complex(double r, double i);

double Complex::real()
{
	return realValue;
}

double Complex::imag()
{
	return imaginaryValue;
}

double Complex::norm()
{
	return sqrt(pow(realValue, 2) + pow(imaginaryValue, 2));
}


double real(Complex c)
{
	return c.real();
}

double imag(Complex c)
{
	return c.imag();
}

double norm(Complex c)
{
	return c.norm();
}

Complex Complex::operator+(Complex c)
{
	return Complex(realValue + c.real(), imaginaryValue + c.imag());
}

Complex Complex::operator-(Complex c)
{
	return Complex(realValue - c.real(), imaginaryValue - c.imag());
}

Complex Complex::operator*(Complex c)
{
	return Complex(realValue * c.real() - imaginaryValue * c.imag(), imaginaryValue * c.real() + realValue * c.imag());
}

Complex Complex::operator/(Complex c)
{
	return Complex((realValue * c.real() + imaginaryValue * c.imag()) / (pow(c.real(),2)+pow(c.imag(),2)), (imaginaryValue * c.real() - realValue * c.imag()) / (pow(c.real(), 2) + pow(c.imag(), 2)));
}

Complex operator+(double d, Complex c)
{
	return Complex(d) + Complex(c);
}

Complex operator-(double d, Complex c)
{
	return Complex(d) - Complex(c);
}

Complex operator*(double d, Complex c)
{
	return Complex(d) * Complex(c);
}

Complex operator/(double d, Complex c) 
{
	return Complex(d) / Complex(c);
}

bool operator==(Complex c1, Complex c2) 
{
	return (c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue);
}

ostream& operator<<(ostream& strm, const Complex& c) 
{
	strm << c.realValue;
	if (c.imaginaryValue >= 0)
	{
		strm << " + " << c.imaginaryValue << "*i";
	}
	else if (c.imaginaryValue < 0)
	{
		strm << " + " << c.imaginaryValue << "*i";
	}
	return strm;
}

istream& operator>>(istream& strm, Complex& c) 
{
	char via, equalsign, plussign, mulsign, i;
	strm >> via >> equalsign;
	double realnum, imagnum;
	strm >> realnum >> plussign >> imagnum >> mulsign >> i;
	c.realValue = realnum;
	c.imaginaryValue = imagnum;
	return strm;
}