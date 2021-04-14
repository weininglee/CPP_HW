#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lena, lenb;
string a, b;
int dp[1010][1010];

void work() //ºtºâªk
{
	for (int i = 1; i <= lena; i++)
	{
		dp[i][0] = i;
	}
	for (int j = 1; j <= lenb; j++)
	{
		dp[0][j] = j;
	}
	for (int i = 1; i <= lena; i++){
		for (int j = 1; j <= lenb; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
			}
		}
	}
		cout << dp[lena][lenb] << endl;
	
}

int main() {
	while (getline(cin, a, '\n'))
	{
		getline(cin, b, '\n');
		lena = a.length();
		lenb = b.length();
		work();
	}
	return 0;
}