#include<iostream>
#include<stack>
#include<algorithm>

//백준 2667

using namespace std;

stack<pair<int, int>> stk;
int map[27][27];
int group[5000];
int check[27][27];
int grp_cnt=0;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
void dfs(int y, int x) {
	check[y][x] = 1;
	group[grp_cnt]++;
	for (int i = 0; i < 4; i++) {
		int nowX = x + dx[i];
		int nowY = y + dy[i];
		if (!check[nowY][nowX] && map[nowY][nowX])
			dfs(nowY, nowX);
	}
}
int N;
int main() {
	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%1d", &map[y][x]); //지도 입력
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!check[i][j] && map[i][j]) {
				dfs(i, j); grp_cnt++;
			}
		}
	}
	cout << grp_cnt<<endl;
	sort(group, group + grp_cnt);
	for (int i = 0; i < grp_cnt; i++) {
		cout << group[i] << endl;
	}
}