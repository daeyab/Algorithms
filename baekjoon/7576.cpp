#include<iostream>
#include<queue>

using namespace std; 

int map[1001][1001];
int visited[1001][1001];
int x,y,days;
int M, N;
queue <pair<pair<int, int>, int>> q; // tomato 의 y, x, days 

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };

bool checkzero() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0)
				return false;
		}
	}
	return true;
}
void BFS() {
	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		days = q.front().second;
		visited[y][x] = 1;
		//map[y][x] = days;
		//days++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx>0 && ny >0 && nx<=M && ny<=N&& map[ny][nx] == 0 && visited[ny][nx] == 0 && map[y][x]!=-1) {
				map[ny][nx] = days+1;
				q.push(make_pair(make_pair(ny, nx), days + 1));
			}
		}
	}
	if (!checkzero())//0인 것 있으면 빠꾸 아니면 최종 값 반환
		cout << -1 << endl;
	else
		cout<<days<<endl;

}

int main() {
	cin >> M >> N;

	for(int i = 1; i <= N; i++) {	
		for (int j = 1; j <= M; j++) {
			if (i == 0 || i == N+1 || j == 0 || j == M+1)
				visited[i][j] == 1; //테두리 방문 체크 값 빼주기 
			cin >> map[i][j];
			if(map[i][j])
				q.push(make_pair(make_pair(i, j), 0));
		}
	}

	BFS();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
		//	cout << " | y:" << j << " x:" << i << " days:" << map[i][j];
		}
		//cout << endl;
	}
	return 0;

}