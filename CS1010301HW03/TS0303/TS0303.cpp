#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double x;
	while (cin >> x)
	{
		int m, n, count = 0, fill;
		char c;
		cin >> m >> n >> c;
		unsigned absX = abs(x);

		//т俱计场だΤ碭计
		while (absX >= pow(10.0, count))
		{
			++count;
		}

		//狦琌璽计, 计
		if (x < 0.0)
			++count;

		//块Τ计
		if (n > 0)
		{
			fill = m - n - 1 - count;
			for (int i = 0; i < fill; i++)
			{
				cout << c;
			}
			if (x > 0.0)
				x -= 0.0000000009;
			else if (x < 0.0)
				x += 0.0000000009;

			cout << fixed << setprecision(n) << x << endl;
		}
		//块⊿Τ计
		else
		{
			fill = m - count;
			for (int i = 0; i < fill; i++)
			{
				cout << c;
			}
			cout << (int)x << endl;
		}
	}
}