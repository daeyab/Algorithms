#include<bits/stdc++.h>
 
using namespace std;
 
 
class Node {
	public:
	string name;
	int depth;
	//아래 노드의 개수, root 까지의 거리
} node[205]; // node structure
 
vector<int> edges[2005];
map<string,int> m[205];
 
bool visited[205];
long long ans = -1;
 
 
void dfs(int pos) {
	//a[pos].dist <- known
	//edges 0-> 끝까지
	visited[pos] = true;
	for (int i = 0; i < edges[pos].size(); i++) {
		if (!visited[edges[pos][i]]) { // 방문하지 않은 경우
			node[edges[pos][i]].depth = node[pos].depth + 1;
			if (ans < node[edges[pos][i]].depth)
				ans = node[edges[pos][i]].depth;
			dfs(edges[pos][i]);
		}
	}
}
 
int main() {
	int n;
	int cnt = 1;
	scanf("%d", &n);
	m->insert(make_pair("polycarp", 0));
	node[0].name = "polycarp";
	node[0].depth = 1;
	for (int i=1; i <= n; i++) {
		char s1[30], s2[30], s3[30];
			scanf("%s %s %s", &s1, &s2, &s3);
			for (int k = 0; k < 30; k++) {
				s1[k] = tolower(s1[k]);
				s3[k] = tolower(s3[k]);
			}
		//	printf("%s! %s! %s!", s1, s2, s3);
 
		
		int idx1 = m->find(s3)->second;
		m->insert(make_pair(s1, i));
		int idx2 = m->find(s1)->second;
		edges[idx1].push_back(idx2);
		edges[idx2].push_back(idx1);
 
		
	}
	//standard dfs
	dfs(0); //모든 노드의 cnt,dist 가 설정
	printf("%lld\n", ans);
	return 0;
}