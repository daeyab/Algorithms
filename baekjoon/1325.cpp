#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<memory.h>

//백준 1325
//2019-03-18

using namespace std;
 
int N, M;
vector<vector<int>> map(10001);
int ans[10001] = { 0, };
bool visited[10001] = { 0, };
int cnt;
vector<int> a;

void dfs(int x) {
	if (visited[x])
		return;
	cnt++;
	visited[x] = true;
	for (int i = 0; i <map[x].size(); i++) {
		int here= map[x][i];
		if (!visited[here]) {

			dfs(here);
		}
	}
}
int main() {
	cin >> N >> M;
	while (M--) {
		int a, b; cin >> a >> b;
		map[b].push_back(a);
	}
	int max = -1;
	for (int i = 1; i <= N; i++) {
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		dfs(i);
		ans[i] = cnt;
		if (cnt >= max)
			max = cnt;
	}

	for (int i = 1; i <= N; i++) {
		if (ans[i] == max)
			cout << i << " ";
		}

	return 0;
}
