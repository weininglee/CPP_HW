#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ifstream file;
	file.open("name.txt");
	set<string> words;
	string s;
	while (getline(file,s)) {
		auto iter = words.find(s);
		if (iter == words.end()) {
			words.insert(s);
			//cout << s << endl;
		}
	}
	for (auto i = words.begin(); i != words.end(); i++) {
		cout << *i << endl;
	}
}