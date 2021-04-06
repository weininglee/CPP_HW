#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<string> name, salary, bonus;
		int name_max = 0, salary_max = 0, bonus_max = 0;
		for (int i = 0; i < n; i++) {
			string na, s, b;
			cin >> na;
			cin >> s;
			cin >> b;
			name.push_back(na);
			salary.push_back(s);
			bonus.push_back(b);
			if (na.size() > name_max)
				name_max = na.size();
			if (s.size() > salary_max)
				salary_max = s.size();
			if (b.size() > bonus_max)
				bonus_max = b.size();
		}
		for (int i = 0; i < n; i++) {
			cout << setw(name_max) << name[i] << "|  " << setw(salary_max) << salary[i] << "|  " << setw(bonus_max) << bonus[i] << endl;
		}
	}
}