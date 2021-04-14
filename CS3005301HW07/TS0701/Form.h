#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Form
{
private:
	string inputWord;

public:
	string fileName;
	string compareWord;
	int* check = new int;
	vector<string> validWord;
	int checkSize;
	bool flag = false;

	void SetInputWord(string inputWord); // set input
	void ProcessInputWord(); // process input
	void SetFileName(string fileName); // set file name
	void Load_CompareWord(); // read-in data and compare
	void PrintFoundWords(); // print answers
	
};
