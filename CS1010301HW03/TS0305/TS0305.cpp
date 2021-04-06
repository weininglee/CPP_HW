#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Draw {
	vector<vector<bool>> xy;
	int x , y;
	bool is_error;
};

enum string_code {
	eRU,
	eRD,
	eLD,
	eLU
};

string_code hashdir(string const& inString) {
	if (inString == "RU") return eRU;
	if (inString == "RD") return eRD;
	if (inString == "LU") return eLU;
	if (inString == "LD") return eLD;
}

void square(Draw& draw, int w, int x, int y) {
	if (x + w > draw.x || y + w > draw.y) {
		draw.is_error = true;
	}
	else {
		for (int i = y; i < y + w; i++) {
			for (int j = x; j < x + w; j++) {
				draw.xy[i][j] = true;
			}
		}
	}
}

void triangle(Draw& draw, int w, int x, int y, string const dir) {
	switch (hashdir(dir)) {
		case eRD:
			if (x + w > draw.x || y + w > draw.y) {
				draw.is_error = true;
			}
			else {
				for (int i = 0; i < w; i++) {
					for (int j = 0; j < w; j++) {
						if (i + j < w) {
							draw.xy[i + y][j + x] = true;
						}
					}
				}
			}
			break;
		case eRU:
			if (x + w > draw.x || y - w < -1) {
				draw.is_error = true;
			}
			else {
				int count = w;
				for (int i = 0; i < w; i++) {
					for (int j = 0; j < w; j++) {
						if ( j < count) {
							draw.xy[y][j + x] = true;
						}
					}
					count--;
					y--;
				}
			}
			break;
		case eLD:
			if (x - w < -1 || y + w > draw.y) {
				draw.is_error = true;
			}
			else {
				int count = w;
				for (int i = 0; i < w; i++) {
					for (int j = 0; j < w; j++) {
						if (j < count) {
							draw.xy[y][x - j] = true;
						}
					}
					count--;
					y++;
				}
			}
			break;
		case eLU:
			if (x - w < -1 || y - w < -1) {
				draw.is_error = true;
			}
			else {
				for (int i = 0; i < w; i++) {
					for (int j = 0; j < w; j++) {
						if (i + j >= w-1) {
							draw.xy[y - w + 1 + i][x - w + 1 + j] = true;
						}
					}
				}
			}
			break;
	}
}

void line(Draw& draw, int x1, int y1, int x2, int y2) {
	if (x1 >= draw.x || x1 < 0 || x2 >= draw.x || x2 < 0 || y1 >= draw.y || y1 < 0 || y2 >= draw.y || y2 < 0) {
		draw.is_error = true;
	}
	else {
		if (x1 == x2) {
			if (y1 > y2) {
				for (int i = 0; i < y1 - y2 + 1; i++) {
					draw.xy[y2 + i][x1] = true;
				}
			}
			else {
				for (int i = 0; i < y2 - y1 + 1; i++) {
					draw.xy[y1 + i][x1] = true;
				}
			}
		}
		else if (y1 == y2) {
			if (x1 > x2) {
				for (int i = 0; i < x1 - x2 + 1; i++) {
					draw.xy[y1][x2 + i] = true;
				}
			}
			else {
				for (int i = 0; i < x2 - x1 + 1; i++) {
					draw.xy[y1][x1 + i] = true;
				}
			}
		}
		else {
			if (x1 < x2) {
				if (y1 < y2) {
					int n = x1, m = y1;
					for (int i = 0; i < x2 - x1 + 1; i++) {
						draw.xy[m][n] = true;
						n++;
						m++;
					}
				}
				else {
					int n = x1, m = y1;
					for (int i = 0; i < x2 - x1 + 1; i++) {
						draw.xy[m][n] = true;
						n++;
						m--;
					}
				}
			}
			else {
				if (y1 < y2) {
					int n = x1, m = y1;
					for (int i = 0; i < x1 - x2 + 1; i++) {
						draw.xy[m][n] = true;
						n--;
						m++;
					}
				}
				else {
					int n = x1, m = y1;
					for (int i = 0; i < x1 - x2 + 1; i++) {
						draw.xy[m][n] = true;
						n--;
						m--;
					}
				}
			}
		}
	}
}

void print(Draw& draw) {
	if (draw.is_error == true)
		cout << "Out of range." << "\n" << endl;
	else {
		for (int i = 0; i < draw.y; i++) {
			for (int j = 0; j < draw.x; j++) {
				if (draw.xy[i][j] == true)
					cout << "X";
				else
					cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main() {
	int m, n, x, y, x1, y1, x2, y2, w;
	string type, dir;
	Draw draw;
	cin >> m >> n;
	draw.xy.resize(n);
	for (int i = 0; i < n; i++) {
		draw.xy[i].resize(m);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			draw.xy[i][j] = false;
		}
	}
	draw.x = m;
	draw.y = n;
	while (cin >> type) {
		draw.is_error = false;
		if (type == "EXIT")
			break;
		switch (type[0]) {
		case 'S':
			cin >> w >> x >> y;
			square(draw, w, x, y);
			break;
		case 'T':
			cin >> w >> x >> y >> dir;
			triangle(draw, w, x, y, dir);
			break;
		case 'L':
			cin >> x1 >> y1 >> x2 >> y2;
			line(draw, x1, y1, x2, y2);
			break;
		}
		print(draw);
	}
}