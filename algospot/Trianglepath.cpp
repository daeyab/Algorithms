#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int map[101][101];
int dp[101][101];
int n;

int TRIANGLEPATH(int y, int x) {
	//기저사례
	if (y == n - 1)
		return map[y][x];
	//
	int& ret = dp[y][x];

	if (ret != -1)
		return ret;

		return ret = max(TRIANGLEPATH(y + 1,x), TRIANGLEPATH(y + 1,x + 1)) + map[y][x];
		
}
int main() {
	int tc;
	cin >> tc;
	if (tc < 0 || tc>50)
		exit(-1);
	while (tc--) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		if (n < 2 || n>100)
			exit(-1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> map[i][j];
				if (map[i][j] < 1 || map[i][j]>100000)
					exit(-1);
			}
		}
		TRIANGLEPATH(0, 0);
	
		cout << dp[0][0] << endl;
	}
	return 0;
}