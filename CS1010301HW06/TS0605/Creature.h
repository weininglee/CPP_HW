#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Body {
	string base;
	int number = 0;
};

class Creature 
{
private:
	string name;
	string date;

public:
	Creature(string name);
	Creature(string name2, Creature name1);

	void compare(int old, int now);
	void PrintStatus();
	void PrintLog();

	Creature& operator[](string baseName);
	void operator=(int number);
	void operator+=(int number);
	void operator-=(int number);

	vector<Body> fullBody;
	int currentBase = 0;
	string record;
};