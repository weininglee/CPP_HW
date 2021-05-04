#include "Memory.h"
Memory::Memory()//constructor method
{
	size = 0;
	data.clear();
}

Memory::Memory(int size)//constructor method
{
	this->size = size;
	for (int i = 0; i < size; i++)
	{
		data.push_back(0);
	}
}
int stringToInt(string s)//string锣Θint
{
	int n = 0;
	int c = 1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		n += (s[i] - '0') * c;
		c *= 10;
	}
	return n;
}


void Memory::setMemory(int loc, string type, string val)//砞﹚method把计のじ
{
	if (loc >= size || loc < 0)
	{
		cout << "Violation Access." << endl;
	}
	else
	{
		int vali;
		if (type == "char")
		{
			data[loc] = stringToInt(val);
			//if (data[loc] == 65) {
				//cout << loc << " " << data[loc];
			//}
		}
		else if (type == "String")
		{
			if (loc + val.length() > size )
			{
				cout << "Violation Access." << endl;
			}
			for (int i = 0; i < val.length() ; i++)
			{
				//if (val[i] == 'A') {
					//cout << loc << " " << val[i];
				//}
				data[i + loc] = val[i];
			}
		}
		else if (type == "int" || type == "short")
		{
			if (type == "int")
			{
				if (loc + 4 > size )
				{
					cout << "Violation Access." << endl;
				}
			}
			if (type == "short")
			{
				if (loc + 2 > size )
				{
					cout << "Violation Access." << endl;
				}
			}
			vali = stringToInt(val);
			vector<int> k;
			int temp = 0;
			int c = 1;
			while (vali > 0)
			{
				temp += (vali % 16) * c;
				if (c == 16)
				{
					c = 1;
					k.push_back(temp);
					temp = 0;
				}
				else
				{
					c *= 16;
				}
				vali /= 16;
			}
			for (int i = 0; i < k.size(); i++)
			{
				if (loc+i >= size) {
					break;
				}
				data[i + loc] = k[i];
			}
		}
	}
}

void Memory::getMemory(int loc, string type)//块ㄏノ把计
{
	if (loc >= size || loc < 0)
	{
		cout << "Violation Access." << endl;

	}
	else
	{
		if (type == "String")
		{
			reverse(data.begin(), data.end());
			int end;
			for (int i = 0; i < data.size(); i++) {
				if (data[i] != 0) {
					end = i ;
					break;
				}
			}
			reverse(data.begin(), data.end());
			while (loc < size) {

				cout << (char)data[loc++];

				if (loc == size - end) {
					break;
				}
			}
		}
		else if (type == "char")
		{
			if (data[loc] == 0) {
				cout << 128;
				
			}
			else {
				cout << data[loc];
			}
		}
		else if (type == "short")
		{
			if (loc + 2 > size)
			{
				cout << "Violation Access." << endl;
				/*int temp = 0;
				int count = 0;
				for (int i = 0; i < loc + 2 - size + 1; i++) {
					temp += data[loc + i] * pow(16, count);
					count += 2;
				}
				cout << temp;*/
			}
			else
			{
				int temp = 0;
				temp += data[loc];
				temp += data[loc + 1] * 16 * 16;
				cout << temp;
			}
		}
		else if (type == "int")
		{
			if (loc + 4 > size )
			{
				cout << "Violation Access." << endl;
				/*int temp = 0;
				int count = 0;
				for (int i = 0; i < loc + 4 - size + 1; i++) {
					temp += data[loc + i] * pow(16, count);
					count += 2;
				}
				cout << temp;*/
			}
			else
			{
				int temp = 0;
				temp += data[loc];
				temp += data[loc + 1] * 16 * 16;
				temp += data[loc + 2] * 16 * 16 * 16 * 16;
				temp += data[loc + 3] * 16 * 16 * 16 * 16 * 16 * 16;
				cout << temp;
			}
		}
		cout << endl;
	}
}