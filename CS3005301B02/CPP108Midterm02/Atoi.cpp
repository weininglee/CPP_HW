#include "Atoi.h"

Atoi::Atoi()
{
	beTrans = "";
	sign = '+';
}

Atoi::Atoi(string s)
{
	sign = '+';
	if (s[0] == '-')
	{
		sign = '-';
		s.erase(0, 1);
	}
	beTrans = s;
}

void Atoi::SetString(string s)
{
	sign = '+';
	if (s[0] == '-')
	{
		sign = '-';
		s.erase(0, 1);
	}
	beTrans = s;
}

const string Atoi::GetString()
{
	return beTrans;
}

int Atoi::Length()
{
	return beTrans.size();
}

bool Atoi::IsDigital()
{
	for (int i = 0; i < beTrans.size(); i++)
	{
		if (beTrans[i] < 48 || beTrans[i] > 57)
		{
			return false;
		}
	}
	return true;
}

int Atoi::StringToInteger()
{
	int number = 0;
	for (int i = 0; i < beTrans.size(); i++)
	{
		number *= 10;
		number += (beTrans[i] - 48);
	}
	if (sign == '-')
	{
		number *= -1;
	}
	return number;
}