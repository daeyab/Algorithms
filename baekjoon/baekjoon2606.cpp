#include<iostream>
#include<stack>
//백준 2606
using namespace std;

stack<int> stk;
bool computer[101][101];
bool visited[101];
int N, connection;
int cnt = 0;

void dfs(int n) {
	stk.push(n);
	visited[n] = 1;
	for (int i = 1; i <= N; i++) {
		if (computer[n][i] == 1 && !visited[i]) {
			cnt++;
			dfs(i);
		}
	}
	stk.pop();
}


int main() {
	cin >> N >> connection;
	for (int i = 0; i < connection; i++) {
		int a, b;
		cin >> a >> b;
		computer[a][b] = 1;
		computer[b][a] = 1;
	}
	dfs(1);
	cout <<cnt<<endl;
	return 0;
}