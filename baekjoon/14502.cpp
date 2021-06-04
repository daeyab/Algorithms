#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <queue>
#include <vector>
#define MAX_POINT 3
using namespace std;

struct point {
    int x, y;
};
int n, m, map[8][8], tmp[8][8], dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1},
                                ans = 0;
bool visited[8][8];
vector<point> picked;

void copyMap() {
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++) tmp[y][x] = map[y][x];
}

void initMap() {
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++) map[y][x] = tmp[y][x];
}

void getMaxSafe() {
    copyMap();
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (tmp[y][x] == 2) {
                //각 2를 만나는 곳 마다 BFS를 하면 되는 것 아님?
                point p;
                queue<point> q;
                memset(visited, 0, sizeof(visited));
                p.x = x, p.y = y;
                q.push(p);
                while (!q.empty()) {
                    point f = q.front();
                    int sx = f.x, sy = f.y;
                    visited[sy][sx] = true;
                    for (int i = 0; i < 4; i++) {
                        int ny = sy + dy[i];
                        int nx = sx + dx[i];
                        if (-1 < ny && ny < n && -1 < nx && nx < m &&
                            tmp[ny][nx] == 0 && !visited[ny][nx]) {
                            tmp[ny][nx] = 3;
                            visited[ny][nx] = true;
                            point np;
                            np.x = nx, np.y = ny;
                            q.push(np);
                        }
                    }
                    q.pop();
                }
            }
        }
    }
    int cnt = 0;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            if (tmp[y][x] == 0) cnt++;
    ans = max(cnt, ans);
}

void pickWalls(int cnt, int sY, int sX) {
    if (cnt == MAX_POINT) {
        getMaxSafe();
        return;
    }
    for (int y = sY; y < n; y++) {
        for (int x = sX; x < m; x++) {
            if (map[y][x] == 0) {
                //첫 0인 지점을 찾은 시점
                point p;
                p.x = x, p.y = y;
                picked.push_back(p);
                map[y][x] = 4;
                pickWalls(cnt + 1, y, x);
                picked.pop_back();
                map[y][x] = 0;
            }
        }
        sX = 0;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &map[y][x]);
        }
    }
    pickWalls(0, 0, 0);
    printf("%d\n", ans);
}