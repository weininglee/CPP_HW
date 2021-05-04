#include<iostream>
#include<string>
using namespace std;

int main() {
	int m, n;
	char in1, in2;
	char digit1, digit2;
	string word1, word2;
	while (cin >> m >> n) {
		if (m == 0 && n == 0) break;
		char matric[27][27];
		matric[0][0] = '0';
		for (int i = 1; i < 27; i++) {
			for (int j = 1; j < 27; j++) {
				matric[i][j] = '0';
			}
		}

		for (int i = 1; i < 27; i++) {
			matric[0][i] = (char)(i + 96);
		}
		for (int i = 1; i < 27; i++) {
			matric[i][0] = (char)(i + 96);
		}

		/*for (int i = 0; i < 27; i++) {
			for (int j = 0; j < 27; j++) {
				cout << matric[i][j];
			}
			cout << endl;
		}*/

		for (int i = 0; i < m; i++) {
			cin >> in1 >> in2;
			matric[(int)in1 - 96][(int)in2 - 96] = '1';
		}

		/*for (int i = 0; i < 27; i++) {
			for (int j = 0; j < 27; j++) {
				cout << matric[i][j];
			}
			cout << endl;
		}*/

		for (int i = 1; i < 27; i++) {
			for (int j = 1; j < 27; j++) {
				if (matric[j][i] == '1' && i != j) {
					for (int k = 1; k < 27; k++) {
						if (matric[i][k] == '1') {
							matric[j][k] = '1';
						}
					}
				}
			}
		}

		/*for (int i = 0; i < 27; i++) {
			for (int j = 0; j < 27; j++) {
				cout << matric[i][j];
			}
			cout << endl;
		}*/
		
		for (int i = 0; i < n; i++) {
			int index = 0;
			cin >> word1 >> word2;
			if (word1.size() != word2.size()) {
				goto END;
			}
			
			for (index; index < word1.size(); index++) {
				digit1 = word1[index];
				digit2 = word2[index];
				//cout << (int)digit1 - 96 << " " << (int)digit2 - 96 << endl;
				if (matric[(int)(digit1) - 96][(int)(digit2) - 96] == '1' || digit1 == digit2) {
					//cout << matric[(int)(digit1)-96][(int)(digit2)-96] << endl;
					continue;
				}
				else {
					index--;
					goto END;
				}
			}

			END:
			if (index == word1.size()) {
				cout << "yes" << endl;
			}
			else {
				cout << "no" << endl;
			}
		}
	}
}