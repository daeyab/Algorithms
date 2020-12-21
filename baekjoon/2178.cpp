#include<iostream>
#include<queue>

using namespace std;

int map[102][102];
int visited[102][102];

int M, N;
int cnt = 1;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1,-1, 0, 0 };

queue<pair<pair<int, int>,int>> q;

void bfs(int y, int x) {

	q.push(make_pair(make_pair(y, x),cnt));
	while (!q.empty()) {
		int Y = q.front().first.first;
		int X = q.front().first.second;
		int dist = q.front().second;
		
		q.pop();
		visited[Y][X] = dist;
		for (int i = 0; i < 4; i++) {
			int nx = X + dx[i];
			int ny = Y + dy[i];
			if (visited[ny][nx] == 0 && map[ny][nx] == 1) {
				q.push(make_pair(make_pair(ny,nx),visited[ny][nx]=dist+1));
			}
		}
	}
}

int main() {
	cin >> M >> N;
	for (int y = 1; y <= M; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%1d",&map[y][x]);
		}
	}//설정 완료

	bfs(1, 1);

	for (int y = 1; y <= M; y++) {
		for (int x = 1; x <= N; x++) {
		//	cout << map[y][x] << "visited(" << visited[y][x] << ") ";
		}
	//	cout << endl;
	}
	cout << visited[M][N] << endl;
}