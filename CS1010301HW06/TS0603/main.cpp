#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<set>
#include "NumberGame.h"
using namespace std;

int main() {
	NumberGame Game;
	Game.SetInput(1234);
	Game.ProcessInput();
	Game.SetFileName("number.txt");
	Game.LoadNumberList();
	Game.PrintAllValid();

	Game.Reset();
	cout << "\n";
	Game.SetInput(2345);
	Game.ProcessInput();
	Game.SetFileName("number.txt");
	Game.LoadNumberList();
	Game.PrintAllValid();
}