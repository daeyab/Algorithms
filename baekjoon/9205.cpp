#include <bits/stdc++.h>

using namespace std;

const int MAX = 102;
vector<int> graph[MAX];
vector<pair<int, int> > marketList;
bool visited[MAX];

int dist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
void dfs(int now) {
    visited[now] = true;
    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i];
        if (!visited[next]) dfs(next);
    }
}
int main() {
    int tc, marketCnt, tmpX, tmpY;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &marketCnt);
        for (int i = 0; i < MAX; i++) graph[i].clear();
        memset(visited, false, sizeof(visited));
        marketList.clear();
        for (int i = 0; i < marketCnt + 2; i++) {
            scanf("%d %d", &tmpX, &tmpY);
            marketList.push_back(make_pair(tmpX, tmpY));
        }
        for (int i = 0; i < marketCnt + 2; i++) {
            for (int j = i + 1; j < marketCnt + 2; j++) {
                if (dist(marketList[i], marketList[j]) <= 1000) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        dfs(0);
        // string res = visited[marketCnt + 1] ? "happy" : "sad";
        // printf("%s\n", res.c_str());
        if (visited[marketCnt + 1])
            printf("happy\n");
        else
            printf("sad\n");
    }
}