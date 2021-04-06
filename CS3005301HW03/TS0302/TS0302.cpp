#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream file_in,file_out;
	file_in.open("grade.txt");
	file_out.open("grades.output", ios::out);
	int g, grade[6] = { 0 };
	while (file_in >> g) {
		if (g == 0) {
			grade[0]++;
		}
		else if(g == 1){
			grade[1]++;
		}
		else if (g == 2) {
			grade[2]++;
		}
		else if (g == 3) {
			grade[3]++;
		}
		else if (g == 4) {
			grade[4]++;
		}
		else if (g == 5) {
			grade[5]++;
		}
	}
	for (int i = 0; i <= 5; i++) {
		file_out << grade[i] << " grade(s) of " << i << endl;
	}
}