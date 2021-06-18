#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	map<string, int> map;
	vector<string> list;
	string type, name;
	int grade;
	while (cin >> type) {
		if (type == "Add") {
			cin >> name >> grade;
			if (map.find(name) == map.end()) {
				map.insert(pair<string, int>(name, grade));
				list.push_back(name);
			}
		}
		else if (type == "Average") {
			double ave = 0;
			for (auto index = map.begin(); index != map.end(); index++) {
				ave += index->second;
			}
			ave /= map.size();
			if (ave == (int)ave) {
				cout << (int)ave << endl;
			}
			else if (floor(ave * 100) / 100 == floor(ave * 10) / 10) {
				cout << fixed << setprecision(1) << floor(ave * 10) / 10 << endl;
			}
			else {
				cout << fixed << setprecision(2) << floor(ave * 100) / 100 << endl;
			}
		}
		else if (type == "Pass") {
			for (int index = 0; index < list.size(); index++) {
				if (map[list[index]] >= 60) {
					cout << list[index] << " " << map[list[index]] << endl;
				}
			}
		}
		else if (type == "Search") {
			cin >> name;
			if (map.find(name) != map.end()) {
				cout << map.find(name)->first << " " << map.find(name)->second << endl;
			}
		}
	}
}