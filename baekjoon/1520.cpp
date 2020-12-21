#include<iostream>
#include<algorithm>

using namespace std;
int n;

int map[501][10001];
int dp[501][10001];
int sum;
int height, width;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

int dfs(int y, int x) {
	if (x == 1 && y == 1)
		return dp[y][x]=1;
	if (dp[y][x] == -1) { //방문하지 않은 노드들 
		dp[y][x] = 0;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (map[y][x] < map[ny][nx] && nx <= width && ny <= height)
				dp[y][x] += dfs(ny, nx);
		}
	}
	return dp[y][x];
}
int main() {
	cin >> height >> width;
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	dfs(height, width);
	
	/*for (int y = 1; y <= height; y++) {
		for (int x = 1; x <= width; x++)
			cout << "[" << y << "," << x << "] " << map[y][x] << " ";
		cout << endl;
	}

	
	for (int y = 1; y <= height; y++) {
		for (int x = 1; x <= width; x++)
			cout <<"["<<y << "," << x << "] " << dp[y][x] << " ";
		cout << endl;
	}*/

	cout << dp[height][width] << endl;
	return 0;
}