#include<iostream>
#include<string>
#include<queue>

using namespace std;

int m, n;
string str;

int map[1001][1001];
int cache[1001][1001][2]; //하나 거리, 하나는 뚫는 여부

bool visited[1001][1001];

int rst = 0;
queue <pair<int, int>> que;


typedef struct { int y, x; } Dir;

Dir moveDir[4] = { {1,0},{-1,0},{0,1},{0,-1} };
int bfs();

int main() {	
	
	cin >> n >> m;
	
	for (int y = 0; y < n; y++) {
		cin>>str;
		for (int x = 0; x < m; x++) {
			if (str.at(x) == '0')
				map[y][x] = 0;
			else if (str.at(x) == '1')
				map[y][x] = 1;
			else
				exit(-1);
		}
	} // 정상 맵 출력


	cout << bfs() << endl;
	/*
	cout << endl;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cout << map[y][x];
		}
		cout << endl;
	}*/

	return 0;
}

int bfs() {
	queue<pair<pair<int, int>,int>> q;
	
	q.push(make_pair(make_pair(0, 0), 1)); //시작점
	cache[0][0][1] = 1;

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first. second;
		int block = q.front().second; //1이면 뚫지 않았다는 거 , 0이면 뚤은 거
		q.pop();

		//도착하면
		if (y == n - 1 && x == m - 1)
			return cache[y][x][block]; // 해당 번째 값을 반환 ㅍ

		for (int i = 0; i < 4; i++) {

			int nx = x + moveDir[i].x;
			int ny = y + moveDir[i].y;

			if (0 <= ny && ny < n && nx >= 0 && nx < m) { // 범위 내에 있을 때
				if (map[ny][nx] == 1 && block) { // 뚫지 않았고 하지만 길이 없다 -> 그래서 뚫어야할 때
					cache[ny][nx][block - 1] = cache[y][x][block] + 1; //한칸 더 이동하되 block은 0으로 바뀜
					q.push(make_pair(make_pair(ny, nx), block-1));
				}

				else if (map[ny][nx] == 0 && cache[ny][nx][block] == 0) {//뚫려있고 방문하지 않았다
					cache[ny][nx][block] = cache[y][x][block] + 1;
					q.push(make_pair(make_pair(ny, nx), block));
				}
			}
;		}
	}
	return -1;
}