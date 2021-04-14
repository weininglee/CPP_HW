#include "VecNf.h"

VecNf::VecNf()
{
	vStart = new float[count];
	count = 0;
}

VecNf::~VecNf() {

}

VecNf::VecNf(float *dest, int cnt)
{
	vStart = new float[cnt];
	vStart = dest;
	count = cnt;
}

VecNf::VecNf(const VecNf& rhs){
	vStart = new float[rhs.count];
	for (int i = 0; i < rhs.count; i++)
	{
		vStart[i] = rhs.vStart[i];
	}
	count = rhs.count;
}
//VecNf(const VecNf& rhs);

int VecNf::Size()
{
	return count;
}

float& VecNf::operator[](int i)
{
	return vStart[i];
}

VecNf VecNf::operator+(VecNf v)
{
	if (count != v.count)
	{
		cout << "dimensions inconsistent" << endl;
		return VecNf();
	}
	else
	{
		float *temp;
		temp = new float[count];
		for (int i = 0; i < count; i++)
		{
			temp[i] = vStart[i] + v.vStart[i];
		}
		return VecNf(temp, count);
	}
}

VecNf VecNf::operator-(VecNf v)
{
	if (count != v.count)
	{
		cout << "dimensions inconsistent" << endl;
		return VecNf();
	}
	else
	{
		float *temp;
		temp = new float[count];
		for (int i = 0; i < count; i++)
		{
			temp[i] = vStart[i] - v.vStart[i];
		}
		return VecNf(temp, count);
	}
}

float VecNf::operator*(VecNf v)
{
	if (count != v.count)
	{
		cout << "dimensions inconsistent" << endl;
		return 0;
	}
	else
	{
		float sum = 0;
		for (int i = 0; i < count; i++)
		{
			sum += (vStart[i] * v.vStart[i]);
		}
		return sum;
	}
}

VecNf operator*(float multi, VecNf v)
{
	float *temp;
	temp = new float[v.count];
	for (int i = 0; i < v.count; i++)
	{
		temp[i] = multi * v.vStart[i];
	}
	return VecNf(temp, v.count);
}

VecNf operator*(VecNf v, float multi)
{
	float *temp;
	temp = new float[v.count];
	for (int i = 0; i < v.count; i++)
	{
		temp[i] = v.vStart[i] * multi;
	}
	return VecNf(temp, v.count);
}

VecNf& VecNf::operator=(VecNf v)
{
	cout << "ASSIGNMENT!!!" << endl;
	count = v.count;
	vStart = v.vStart;
	for (int i = 0; i < v.count; i++)
	{
		vStart[i] = v.vStart[i];
	}
	return *this;
}

ostream &operator<<(ostream &out, VecNf v)
{
	for (int i = 0; i < v.count; i++)
	{
		out << v[i];
	}
	cout << endl;
	return out;
}