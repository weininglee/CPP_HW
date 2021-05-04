#include <iostream>
#include <string>
#include "Polynomial.h"
using namespace std;

int main()
{
	Polynomial empty;
	double one[] = { 1 };
	Polynomial One(one, 1);
	double quad[] = { 0, 0, 0 ,0,0,4};
	double cubic[] = { -2};
	Polynomial q(quad, 6); // q is 3 + 2*x + x*x
	Polynomial c(cubic, 1);// c is 1 + 2*x + 0*x*x + 3*x*x*x
	Polynomial p = q;  // test copy constructor
	Polynomial r;
	r = q;             //test operator=
	r = c;

	cout << "Polynomial q " << endl;
	for (int i = 0; i < 6; i++)
		cout << "term with degree " << i << " has coefficient " << q[i] <<endl;

	cout << "Polynomial c " << endl;
	for (int i = 0; i < 1; i++)
		cout << "term with degree " << i << " has coefficient " << c[i] << endl;
	
	cout << "value of q(2) is " << evaluate(q, 2) << endl;
	cout << "value of p(2) is " << evaluate(p, 2) << endl;
	cout << "value of r(2) is " << evaluate(r, 2) << endl;
	cout << "value of c(2) is " << evaluate(c, 2) << endl;

	r = q + c;
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;

	r = q - c;
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;
	r[5] = 5;
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;
	
	r = q * c;
	cout << "size of q*c is " << r.mySize() << endl;
	cout << "Polynomial r (= q*c) " << endl;

	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;

	cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
	return 0;
}