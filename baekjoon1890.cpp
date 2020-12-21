#include<iostream>

using namespace std; 

long map[101][101];
long  cache[101][101];
int N;

void dp(int y, int x) {
	if (!cache[y][x])
		return;
	int nx = x;
	int ny = y;
	int cnt = 1;
	while (nx > 0) {
		nx--;
		if (map[ny][nx] == cnt)
			cache[ny][nx]+=cache[y][x];
		cnt++;
	}
	nx = x;
	cnt = 1;
	while (ny > 0) {
		ny--;
		if (map[ny][nx] == cnt)
			cache[ny][nx] += cache[y][x];
		cnt++;
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	map[N - 1][N - 1] = cache[N-1][N-1]=1;
//	cout << endl;
	for (int i = N-1; i >=0; i--) {
		for (int j = N-1; j >=0; j--) {
			dp(i, j);
		}
	//	cout << endl;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
	//		cout << cache[i][j] << " ";
		}
	//	cout << endl;
	}

	cout << cache[0][0] << endl;
	return 0;
}