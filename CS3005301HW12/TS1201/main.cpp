#include <iostream>
#include <string>
#include "Memory.h"
using namespace std;
int main()
{
	int size = 0;
	int times = 0;
	while (cin >> size >> times)//��J�j�p�A����
	{
		Memory memory(size);
		for (int i = 0; i < times; i++)
		{
			string function;
			cin >> function;
			int adress = 0;
			cin >> adress;
			string type;
			cin >> type;
			if (function == "Set") //�M�w�өI�s�ƻ�\��
			{
				cin.get();
				string value;
				getline(cin, value, '\n');
				memory.setMemory(adress, type, value);
			}
			else if (function == "Get")
			{
				memory.getMemory(adress, type);
			}
		}
	}
}