#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


int minval = 64;

char case1[8][8] = { { 'B','W','B','W','B','W','B','W' },{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' },{ 'W','B','W','B','W','B','W','B' } ,{ 'B','W','B','W','B','W','B','W' },{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' },{ 'W','B','W','B','W','B','W','B' } };
char case2[8][8] = { { 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' },{ 'W','B','W','B','W','B','W','B' } ,{ 'B','W','B','W','B','W','B','W' },{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' },{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' } };
char mymap[50][50];

int m, n;
string str;
int res;

int check(int y, int x) {
	int cnt = 0;
	int cnt2 = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (mymap[y + i][x + j] != case1[i][j])
					cnt++;
			}
		}
	
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (mymap[y + i][x + j] != case2[i][j])
					cnt2++;
			}
		}

	return min(cnt,cnt2);
}

int main() {
	cin >> m >> n;
	for (int y = 0; y < m; y++) {
		cin >> str;
		for (int x = 0; x < n; x++) {
			mymap[y][x] = str.at(x);
		}
	}
	//print map
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
	//		cout<<mymap[y][x]<<" ";
		}
		//cout << endl;
	}

	for (int i = 0; i <= m - 8; i++) {
		for (int j = 0; j <= n - 8; j++) {
			res = check(i, j);
		//	cout << res<<" ";
			if (res < minval)
				minval = res;
		}
	//	cout << endl;
	}
	cout << minval;

	return 0;
}