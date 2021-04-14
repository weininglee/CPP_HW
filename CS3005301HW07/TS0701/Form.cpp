#include "Form.h"

void Form::SetInputWord(string inputWord) 
{
	this->inputWord = inputWord;
}

void Form::ProcessInputWord() 
{
	for (int i = 0; i < inputWord.size(); i++) 
	{
		if (inputWord[i] > 65 && inputWord[i] < 90) 
		{
			inputWord[i] += 32;
		}
	}
}

void Form::SetFileName(string fileName) 
{
	this->fileName = fileName;
}

void Form::Load_CompareWord() 
{
	fstream file;
	file.open(fileName);
	check = new int[inputWord.size()];
	//for (int m = 0; m < 20; m++) {
	while(file >> compareWord){
		checkSize = 0;
		for (int i = 0; i < inputWord.size(); i++)
		{
			check[i] = 0;
			//cout << check[i] << " ";
		}
		//cout << compareWord.size() << endl;
		for (int i = 0; i < compareWord.size(); i++)
		{
			flag = false;
			for (int j = 0; j < inputWord.size(); j++)
			{
				if (compareWord[i] == inputWord[j] && check[j] != 1)
				{					
					check[j] = 1;
					flag = true;
					break;
				}
			}
			if (flag)
			{
				continue;
			}
			else {
				break;
			}
		}

		for (int i = 0; i < inputWord.size(); i++) {
			if (check[i] == 1)
			{
				checkSize++;
			}
		}

		if (checkSize == compareWord.size()) {
			validWord.push_back(compareWord);
		}
	}
	file.close();
}

void Form::PrintFoundWords() 
{
	for (int i = 0; i < validWord.size(); i++) {
		cout << validWord[i] << endl;
	}
}