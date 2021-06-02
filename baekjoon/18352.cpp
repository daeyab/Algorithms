#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <queue>
#include <vector>
#define MAX_SIZE 300002

using namespace std;

int n, m, k, x, a, b;
int visited[MAX_SIZE];
vector<int> map[MAX_SIZE];
vector<int> ans;
queue<pair<int, int> > q;

void solve(int start, int expectedDist) {
    if (expectedDist == 0) {
        printf("%d\n", start);
        return;
    }
    memset(visited, -1, sizeof(visited));
    q.push(make_pair(start, 0));
    int cur, dist = 0;
    visited[start] = 0;
    while (!q.empty()) {
        cur = q.front().first;
        // cout << "Q:" << cur << endl;
        dist = q.front().second;
        q.pop();
        for (auto near : map[cur]) {
            if (visited[near] < 0) {
               q.push(make_pair(near, dist + 1));
                visited[near] = dist + 1;
            }
        }
    }

    for (int i = 1; i < MAX_SIZE; i++) {
        if (visited[i] == expectedDist) ans.push_back(i);
    }
    if (ans.size() == 0) ans.push_back(-1);
    sort(ans.begin(), ans.end());
    for (auto it : ans) printf("%d\n", it);
}
int main() {
    scanf("%d %d %d %d", &n, &m, &k, &x);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
    }
    solve(x, k);
    return 0;
}