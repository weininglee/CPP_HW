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

		//��X��Ƴ������X���
		while (absX >= pow(10.0, count))
		{
			++count;
		}

		//�p�G�O�t��, ��ƥ[�@
		if (x < 0.0)
			++count;

		//��X���p��
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
		//��X�S���p��
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