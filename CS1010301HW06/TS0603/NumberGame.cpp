#include "NumberGame.h"


void NumberGame::SetInput(int numberInput) 
{
	this->numberA = numberInput;
}

void NumberGame::ProcessInput() 
{
	int tmp = numberA;
	while (tmp > 0)
	{
		int digit = tmp % 10;
		tmp /= 10;
		splitDigit.push_back(digit);
	}
	for (int i = 0; i < splitDigit.size(); i++) 
	{
		check.push_back(false);
	}
	//test
	/*cout << "digits: ";
	for (int i = 0; i < splitDigit.size(); i++) {
	 cout << splitDigit[i]<<" ";
	}
	cout << endl;*/
}

void NumberGame::SetFileName(string file) 
{
	this->fileName = file;
}

void NumberGame::LoadNumberList() 
{
	fstream file;
	file.open(fileName);
	int i;
	while (file >> i)
	{
		inputNumber.push_back(i);
	}
	/*
	for (int i = 0; i < s.size(); i++) {
	 cout << s[i] << " ";
	}
	cout << endl;*/
}

void NumberGame::PrintAllValid() 
{
	for (int i = 0; i <= splitDigit.size(); i++) 
	{
		Combi(splitDigit, i, 0, 0, check, splitDigit.size());
	}

	for (int i = 0; i < inputNumber.size(); i++) 
	{
		if (valid.find(inputNumber[i]) != valid.end()) 
		{
			cout << inputNumber[i] << endl;
		}
	}
}

bool findDigit(vector<int>v, int key) 
{
	for (int i = 0; i < v.size(); i++) 
	{
		if (v[i] == key) 
		{
			return true;
		}
	}
	return false;
}

void NumberGame::Reset() 
{
	numberA = 0;
	inputNumber.clear();
	splitDigit.clear();
	valid.clear();
	fileName = "";
}

void NumberGame::Combi(vector<int>splitDigit, int reqLen, int s, int currLen, vector<bool>check,unsigned int length)
{
	if (currLen > reqLen)
		return;
	else if (currLen == reqLen) 
	{
		int tmp = 1;
		bool loopExecute = false;
		for (int i = 0; i < length; i++) 
		{
			if (check[i] == true) 
			{
				//cout << k[i] << "*";
				tmp *= splitDigit[i];
				loopExecute = true;
			}
		}
		if (loopExecute) 
		{
			valid.insert(tmp);
		}
		//cout <<"="<<tmp << endl;
		//cout << "\n";
		return;
	}
	if (s == length) 
	{
		return;
	}
	check[s] = true;
	Combi(splitDigit, reqLen, s + 1, currLen + 1, check, length);
	check[s] = false;
	Combi(splitDigit, reqLen, s + 1, currLen, check, length);
}