#include<iostream>
#include<queue>

using namespace std; 

int map[101][101][101];
int visited[101][101][101];
queue <pair<pair<int, int>, pair<int, int>>> q;

void BFS() {

}

int M, N, H;
int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 1,-1,0,0,0,0 };
int result;

int main() {
	cin >> M >> N >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1)
					q.push(make_pair(make_pair(0,i), make_pair(j, k)));
			}
		}
	}
	while (!q.empty()) {
	//	cout << "size:" << q.size() << endl;
		int days = q.front().first.first;
		int z = q.front().first.second;
		int y = q.front().second.first;
		int x = q.front().second.second;
	//	cout << "x:" << x << " y:" << y << " z:" << z << endl;
		visited[z][y][x] = true;
		q.pop();
		for (int i = 0; i < 6; i++) { //z,y,x 는 기준 nz,ny,nx 는 내가 갈 곳
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
		//	cout << "nz:" << nz << " ny:" << ny << " nx:" << nx << " visited:" << visited[nz][ny][nx] << " map:" << map[nz][ny][nx] << endl;
			if (nz>0 && ny>0 && nx>0 && nz <= H && ny <= N && nx <= M && map[z][y][x] !=-1 && visited[nz][ny][nx]==false && map[nz][ny][nx]==0) {
				map[nz][ny][nx] = days + 1;
				q.push(make_pair(make_pair(result = days + 1, nz), make_pair(ny, nx)));
		//		cout << 1;
			}
		}
//		result = days;
//		cout << result<<endl;
//		int times = 1;
	//	cout << times++ << "!";
		
	}
//	cout << endl;;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
			//	cout << map[i][j][k] << " ";
					if (map[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		//	cout << endl;
		}
	//	cout << "=======================" << endl;
	}
	cout << result << endl;
	return 0;
}