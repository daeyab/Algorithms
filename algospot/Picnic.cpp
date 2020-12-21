#include<iostream>

using namespace std;

int testcase;
bool friends[10][10];
bool taken[10];
int n,m;
void clean() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			friends[i][j] = 0;
	}
}
int picnic() { //i부터 사람을 확인하는 거 
	int first = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) { //얘는 첫사람 
			first = i;
			break;
		}
	}
	if (first == -1)
		return 1; // 첫사람이 없으면 종료 
	int ret = 0;
	for (int pair = first + 1; pair < n; pair++) { // 뒷 사람들 중 나랑 친군데 아직 안뽑힌 애 있으면 ㄱㄱ 
		if (!taken[pair] && friends[pair][first]) {
			taken[first] = taken[pair] = true;
			ret += picnic(); //추가로 더한다고 보면 됨 
			taken[first] = taken[pair] = false;//그리고 풀어줘야지 
		}
	}
	return ret;
}
int main() {
	cin >> testcase;
	while (testcase--) {
		clean();
		cin >> n >> m;
		int a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			friends[a][b] = 1;
			friends[b][a] = 1;
		}
		cout << picnic() << endl;
	}
	return 0;
}