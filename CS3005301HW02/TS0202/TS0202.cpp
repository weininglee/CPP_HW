#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void getHighScores(vector<int> grade, vector<string> name) {
	int max = 0;
	for (int i = 0; i < grade.size(); i++ ){
		for (int j = 0; j < grade.size() - i - 1; j++) {
			if (grade[j] > grade[j + 1]) {
				int r = grade[j];
				grade[j] = grade[j + 1];
				grade[j + 1] = r;
				string temp = name[j];
				name[j] = name[j + 1];
				name[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << name[name.size() - 1 - i] << "\n" << grade[grade.size() - 1 - i] << endl;
	}
}

int main() {
	string f;
	while (cin >> f) {
		// read file & parse
		// pass into get...()
		// print result 

		fstream file;
		vector<int> grade;
		vector<string> name;
		file.open(f);
		//bool a = file.is_open();
		//cout << a << endl;
		string str;
		while (file >> str) {
			int num; 
			name.push_back(str);
			file >> num;
			grade.push_back(num);
		}
		getHighScores(grade, name);
		file.close();
	}
}