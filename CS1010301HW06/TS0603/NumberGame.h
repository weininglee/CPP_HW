#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<set>
using namespace std;

class NumberGame
{
public:
	int numberA;
	string fileName;
	vector<int>inputNumber;
	vector<int>splitDigit;
	set<int>valid;
	vector<bool>check;

	NumberGame()
	{
		numberA = 0;
		inputNumber.clear();
	}

	void SetInput(int numberA);
	void ProcessInput();
	void SetFileName(string file);
	void LoadNumberList();
	void PrintAllValid();
	bool findDigit(vector<int>v, int key);
	void Reset();
	void Combi(vector<int>k, int reqLen, int s, int currLen, vector<bool>check,unsigned int l);
};