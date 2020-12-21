#include<iostream>
#include<stack>
#include<memory.h>

using namespace std;

int t,m,n,k;
int x, y;
int res=0;
int map[51][51] = { 0, }; //방문 안했으면 0 방문 했으면 01ㅠ
int visited[51][51] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y);

int main(){
	scanf("%d", &t);
	while (t--) {
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		res = 0;
		scanf("%d %d %d", &m,&n,&k);
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			map[x][y] = 1;
		}
	//순회

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
		//		cout<<map[i][j];
			}
		//	cout << endl;
		}


		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				dfs(i,j);
			}
		}
		cout << res << endl;
	}
}

void dfs(int x, int y) {
	//지나고 나면 방문 처리 해야함
	//반복문 종료
	if (x == 50 && y == 50)
		return;

	if (map[x][y] == 1 && visited[x][y]==0) {
		visited[x][y] = 1;
		res++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0||nx>m||ny>n)
				continue;
			if (map[nx][ny] == 1 && visited[nx][ny] == 0) {
				dfs(nx, ny);
				res--;
			}
		}
	}
}