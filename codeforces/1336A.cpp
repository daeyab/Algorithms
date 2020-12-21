#include<bits/stdc++.h>

using namespace std;

vector<int> edges[200005];
bool visited[200005];

class node {
	public:
	int cnt, dist;
	//아래 노드의 개수, root 까지의 거리
	bool operator < (const node& a) const {
		return dist - cnt < a.dist - a.cnt;
	}
} a[200005]; // node structure

int dfs(int pos) {
	//a[pos].dist <- known
	//edges 0-> 끝까지
	visited[pos] = true;
	int cnt = 0;
	for (int i = 0; i < edges[pos].size(); i++) {
		if (!visited[edges[pos][i]]) { // 방문하지 않은 경우
			a[edges[pos][i]].dist = a[pos].dist + 1;
			cnt+=dfs(edges[pos][i]);
		}
	}
	a[pos].cnt = cnt;
	return cnt + 1;
}

int main() {
	long long ans;
	int n, k, p, q;
	scanf("%d %d", &n, &k);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &p, &q);
		edges[p].push_back(q);
		edges[q].push_back(p);
		//standard한 그래프 생성 ㅍ방법
	}
	//standard dfs
	a[1].dist = 0;
	dfs(1); //모든 노드의 cnt,dist 가 설정
	sort(a + 1, a + n + 1);
	ans = 0;
	for (int i = n; i > n - k; i--) {
		ans += a[i].dist - a[i].cnt;
	}
	printf("%lld\n", ans);
	return 0;
}
