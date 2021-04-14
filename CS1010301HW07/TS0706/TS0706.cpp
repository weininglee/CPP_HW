#include <iostream>
using namespace std;

bool check(int game[][8], int x1, int y1, int x2, int y2) {
	if ((abs(x1 - x2) + abs(y1 - y2) == 1) && (game[y1][x1] == game[y2][x2])) {
		//cout << game[y1][x1] << " " << game[y2][x2] << endl;
		return true;
	}

	else if (x1 == x2) {
		int sum = 0;
		for (int i = min(y1, y2) + 1; i < max(y1, y2); i++) {
			sum += game[i][x1];
			//cout << sum << endl;
		}
		if (sum == 0) {
			return true;
		}
	}

	else if (y1 == y2) {
		int sum = 0;
		for (int i = min(x1, x2) + 1; i < max(x1, x2); i++) {
			sum += game[y1][i];
			//cout << sum << endl;
		}
		if (sum == 0) {
			return true;
		}
	}

	return false;
}

bool step(int game[][8], int x1, int y1, int x2, int y2) {
	if (game[y1][x1] != game[y2][x2] || (x1 == x2 && y1 == y2) || game[y1][x1] == 0 || game[y2][x2] == 0) {
		return false;
	}
	//one step
	else if (check(game, x1, y1, x2, y2)) {
		return true;
	}
	//two step
	else if ((check(game, x1, y1, x1, y2) && check(game, x1, y2, x2, y2) && game[y2][x1] == 0) || (check(game, x1, y1, x2, y1) && check(game, x2, y1, x2, y2) && game[y1][x2] == 0)) {
		return true;
	}
	//three step left or right first
	for (int i = 0; i < 8; i++) {
		if (check(game, x1, y1, i, y1) && check(game, i, y1, i, y2) && check(game, i, y2, x2, y2) && game[y1][i] == 0 && game[y2][i] == 0) {
			return true;
		}
	}
	//three step up or down first
	for (int i = 0; i < 8; i++) {
		if (check(game, x1, y1, x1, i) && check(game, x1, i, x2, i) && check(game, x2, i, x2, y2) && game[i][x1] == 0 && game[i][x2] == 0) {
			return true;
		}
	}
	return false;
}

int main() {
	int game[8][8] = { 0 };
	int x1, y1, x2, y2;
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			cin >> game[i][j];
		}
	}
	/*for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << game[i][j];
		}
		cout << endl;
	}*/
	while (cin >> x1 >> y1 >> x2 >> y2) {
		//cout << game[y1+1][x1+1] << " " << game[y2+1][x2+1] << endl;
		if (step(game, x1 + 1, y1 + 1, x2 + 1, y2 + 1)) {
			game[y1 + 1][x1 + 1] = 0;
			game[y2 + 1][x2 + 1] = 0;
			cout << "pair matched" << endl;
		}
		else {
			cout << "bad pair" << endl;
		}
	}
}