#include<iostream>
#include<algorithm>

using namespace std;

//baekjoon:7568
//https://www.acmicpc.net/problem/7568
//Daeyeop Kim
//190215

int info[50][2];
//int rank[50];
int N;

void compare() {
	int rank;
	for (int i = 0; i < N; i++) { // 각 사용자 마다 
		rank = 1;
		for (int j = 0; j < N; j++) { // 모든 사람을 비교
			if (info[i][0] < info[j][0] && info[i][1] < info[j][1]) {
				rank++;
			}
		}
		cout << rank << " ";
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> info[i][0] >> info[i][1];
	}
	compare();
}