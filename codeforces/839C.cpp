#include<bits/stdc++.h>

using namespace std;


class Node {
	public:
	int depth;
	double prob;
	//아래 노드의 개수, root 까지의 거리
} node[100005]; // node structure

vector<int> edges[100005];

bool visited[100005];
long long depthSumofLeaves = 0;
long long countofLeaves = 0;
double ans = 0;
void dfs(int pos) {
	//a[pos].dist <- known
	//edges 0-> 끝까지
	visited[pos] = true;
	bool allvisited = true;
	for (int i = 0; i < edges[pos].size(); i++) {
		if (!visited[edges[pos][i]]) { // pos와 인접한 노드 중 방문하지 않은 경우
			allvisited = false;
			node[edges[pos][i]].depth = node[pos].depth + 1;
			double tmp;
			if (pos == 1) {
				tmp =(double)  1 / edges[pos].size();
//				cout << edges[pos][i] << "!"<< edges[pos].size() <<endl;
				node[edges[pos][i]].prob = tmp;
			}
			else {
				tmp = node[pos].prob * (double) 1 / (edges[pos].size() - 1);
//				cout << edges[pos][i] << "?"<<endl;
				node[edges[pos][i]].prob = tmp;
			}
			dfs(edges[pos][i]);
		}
	}
	if (allvisited) {
		//leaf node
		ans +=(double) node[pos].prob * node[pos].depth;
	//	cout <<pos<< "ans:" << ans <<"prob:"<<node[pos].prob<<"depth:"<<node[pos].depth<<endl;
	}
}

int main() {
	int n,p,q;
	scanf("%d", &n);
	for (int i=1; i <n; i++) {
		scanf("%d %d", &p, &q);
		edges[q].push_back(p);
		edges[p].push_back(q);
	}
	//standard dfs
	node[1].depth = 0;
	node[1].prob = 1.0;
	dfs(1);

//	for (int i = 1; i <= n; i++) {
//		cout << node[i].prob << endl;
//	}
	//printf("%lld\n", depthSumofLeaves);
	//printf("%lld\n", countofLeaves);
	//long double ans = (long double)depthSumofLeaves / (long double)countofLeaves;
	printf("%lf\n", ans);
	return 0;
}
