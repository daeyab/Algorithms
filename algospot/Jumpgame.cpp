#include<iostream>
#include<memory.h>

using namespace std;

int map[102][102];
int dp[102][102];
int n;
int JUMPGAME(int y, int x) {
	if (y > n || x > n)
		return 0;
	if (y == n && x == n)
		return 1;
	int& ret = dp[y][x];
	if (ret != -1)
		return ret;
	int jumpsize = map[y][x];
	return ret = (JUMPGAME(y + jumpsize, x) || JUMPGAME(y, x + jumpsize));
}

int	main() {
	int tc;
	cin >> tc;
	if (tc <= 0 || tc > 50)
		exit(-1);

	while (tc--) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		if (n < 2 || n>100)
			exit(-1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
			}
		}//모두 입력
		int res = JUMPGAME(1, 1);
		if (res)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}