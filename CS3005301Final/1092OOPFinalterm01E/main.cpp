#include<iostream>
#include<vector>
using namespace std;
int sec[1000] = { 0 };

int main() {
	int n,des = 1,now = 1,turn = 1;
	cin >> n;
	int s, f;
	vector<int>sec;
	vector<int>floor;
	for (int i = 0; i < n; i++) {
		cin >> s >> f;
		sec.push_back(s);
		floor.push_back(f);
	}
	int next = 0,nextdes = 1;
	for (int i = 1; i < 1000; i++) {
		

		if (i == sec[next]) {
			if (turn == 1) {
				if (floor[next] > des) {
					des = floor[next];
				}
				else if (floor[next] < des) {
					nextdes = floor[next];
				}
				else if (floor[next] < nextdes) {
					nextdes = floor[next];
				}
			}
			else if (turn == -1) {
				if (floor[next] < des) {
					des = floor[next];
				}
				else if (floor[next] > des) {
					nextdes = floor[next];
				}
				else if (floor[next] > nextdes) {
					nextdes = floor[next];
				}
			}
			if (next < n-1) {
				next++;
			}
		}
		if (next >= n-1 && now == des)break;
		if (des != now) {
			if (des > now) {
				now++;
			}
			else if (des < now) {
				now--;
			}
		}
		else {
			//if (now!=1) {
				turn *= -1;
				des = nextdes;
				//if (turn == -1)now--;
				//if (turn == 1)now++;
			//}
		}
		cout << i << " " << now << endl;
	}
}