#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>

#define MAX (int)pow(2,31)-1

using namespace std;

vector <pair<int, int>> vec;

int endtime = MAX;
int starttime = 0;
int n, a, b, cnt = 0;
int lastfirstTime;

void checktime(int x) { //x시각 이후로 가능한 것들에 대하여

	endtime = MAX;
	starttime = x;

	if (x > lastfirstTime)
		return;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (vec.at(i).second >= x && vec.at(i).second <= endtime) {
			//	cout << "didididi" << endl;
			;			endtime = vec.at(i).second;
			tmp = i;
		}
		//cout <<"x:"<<x<<" endtime: "<<endtime <<endl<<"cnt:"<<cnt ;
	}
	cnt++;
	checktime(endtime);
}

void check() {
	int i, j;
	cnt = 1;
	for (i = 0; i < n - 1;) {
		endtime = vec.at(i).first;
		for (j = i + 1; j < n; j++) {
			if (vec.at(j).second >= endtime) {
				cnt++;
				vec.at(i).second = -1;
				i = j;
				//	cout <<"i:"<<i<<" j:"<<j<< " yaya!" << endl;
				break;
			}
		}
	}
}

int main() {
	cin >> n;
	if (n == 0) {
		cout << 0 << endl;
		return 0;

	}
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		vec.push_back(make_pair(b, a));
	}
	sort(vec.begin(), vec.end());
	//lastfirstTime = vec.at(n - 1).first;
	//cout << endl;
	//cout << lastfirstTime << endl << endl;

//	checktime(starttime);
	//cnt = 1;
//	vec.at(i)
	int e = 0, s = 0;
for (int i = 0; i < n; i++) {
		int begin = vec[i].second, end = vec[i].first;

		if (e <= begin) {
			e = end;
			s++;
		}
	}

cout << s << endl;
	for (int i = 0; i < n; i++) {
		//	cout << vec.at(i).first << " " << vec.at(i).second << endl;
	}
	//check();
//	cout << cnt << endl;
}