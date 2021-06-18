#include<iostream>
#include<string>
using namespace std;

int main() {
	int m, n;
	int book[27][27];
	while (cin >> m >> n) {
		if (m == 0 && n == 0)break;
		for (int i = 0; i < 27; i++) {
			for (int j = 0; j < 27; j++) {
				book[i][j] = 0;
			}
		}
		char a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			if (a < 'a' || a > 'z' || b < 'a' || b > 'z') {
				cout << "ERROR" << endl;
				continue;
			}
			book[(int)a - 96][(int)b - 96] = 1;
		}
		for (int i = 1; i < 27; i++) {
			for (int j = 1; j < 27; j++) {
				if (book[j][i] == 1 && i != j) {
					for (int k = 1; k < 27; k++) {
						if (book[i][k] == 1) {
							book[j][k] = 1;
						}
					}
				}
			}
		}

		string word1, word2;
		int index = 0;
		for (int i = 0; i < n; i++) {
			cin >> word1 >> word2;
			if (word1.size() != word2.size())goto END;
			for (index = 0; index < word1.size(); index++) {
				if (word1[index] < 'a' || word1[index]  > 'z' || word2[index] < 'a' || word2[index] > 'z') {
					cout << "ERROR" << endl;
					goto ERROR;
				}
				if (book[(int)word1[index] - 96][(int)word2[index] - 96] == 1 || word1[index] == word2[index]) {
					continue;
				}
				else {
					index--;
					goto END;
				}
			}

		END:
			if (index == word1.size())cout << "yes" << endl;
			else cout << "no" << endl;
		ERROR:
			continue;
		}

	
	}
}