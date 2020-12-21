#include<iostream>
#include<string>

using namespace std;

int map[21][21];
string str;
int testcase;

int coverType[4][3][2] = {
{{0,0},{1,0},{0,1}},//ㄱ 대칭
{{0,0},{1,0},{1,-1}},//ㄴ 대칭
{{0,0},{0,1},{1,1}},//ㄱ
{{0,0},{1,0},{1,1}} };//ㄴ

bool set(int H,int W,int y, int x, int type, int delta) { 
	bool ok = true;
	//cout << "set xy:"<<x<<","<<y<< endl;
	for (int i = 0; i < 3; i++) { //각 타입마다 모든 원소가 되는지 확인
		int ny = y + coverType[type][i][0];
		int nx = x + coverType[type][i][1];
	//	cout << nx << "," << ny << "는 " << map[x][y]<<endl;
		if (ny < 0 || ny >= H || nx < 0 || nx >= W)
			ok = false;
		else if ( (map[ny][nx] += delta) > 1) //이미 있었던 경우
			ok = false;
	//	cout <<ny<<","<<nx<<")"<< type << "번째 타입에서는 "<<i<<"가"<< ok << endl;
	}
//	cout << x<<","<<y<< "일때 : " << ok << endl;

	return ok;
}

int cover(int H, int W) {
//	cout << "!!" << endl;
	int y = -1, x = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) 
			if (!map[i][j]) { //빈칸이면!
	//			cout << i << "," << j << "는 빈칸" << endl;
				y = i;
				x = j;
				break;
			}
	//		cout << y << "!!!!!!!!!!!!";
			if (y != -1)
				break;
	}
	if (y == -1) {
	//	cout << "이 경우" << endl;
		return 1;
	}
	int ret = 0;
//	cout << "cover x,y:" << x <<","<< y << endl;
	for (int type = 0; type < 4; type++) {
		if (set(H, W, y, x, type, 1))//여기에 둬도 된다는 거{
		{
	//		cout << "됨" << endl;
			ret += cover(H, W); //그러면 다시 진행하는거죠?
	
		}
		set(H,W,y, x, type, -1);
	}
	return ret;
}

int main() {
	int h, w;
	cin >> testcase;
	if (testcase > 30 || testcase < 0)
		exit(-1);

	while (testcase--) {
		cin >> h >> w;
		if (h > 20 || w > 20 || h < 1 || w < 1)
			exit(-1);
		for (int i = 0; i < h; i++) {
			cin >> str;
			for (int j = 0; j < str.length(); j++) {
				if (str.at(j) == '#')
					map[i][j] = 1;
				else
					map[i][j] = 0;
			}
		}

	/*		for (int y = 0; y < h; y++) {
					for (int x = 0; x < w;x++)
						cout << map[y][x] << " ";
					cout << endl;
				}*/

		cout << cover(h,w)<<endl;
	}
	
	return 0;
}