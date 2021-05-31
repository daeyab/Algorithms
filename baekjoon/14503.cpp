#include <math.h>
#include <stdio.h>

#include <iostream>

using namespace std;
int m, n, r, c, d;
int map[55][55];
int ans = 0;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int turn(int d) {
    // printf("TTTT        %d -> %d\n", d, (d + 3) % 4);
    return (d + 3) % 4;
}

void countAns() {
    int ans = 0;
    for (int y = 1; y <= m; y++) {
        for (int x = 1; x <= n; x++) {
            if (map[y][x] == -1) ans++;
        }
    }
    printf("%d\n", ans);
}

void dfs(int y, int x, int d) {
    // printf(" ->>     %d %d/// %d\n", y, x, d);
    map[y][x] = -1;
    for (int i = 0; i < 4; i++) {
        d = turn(d);
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (map[ny][nx] == 0) {
            dfs(ny, nx, d);
            return;
        }
    }
    if (map[y - dy[d]][x - dx[d]] == 1) {
        countAns();
        return;
    } else
        dfs(y - dy[d], x - dx[d], d);
}

int main() {
    scanf("%d %d %d %d %d", &m, &n, &r, &c, &d);
    for (int y = 1; y <= m; y++) {
        for (int x = 1; x <= n; x++) {
            scanf("%d", &map[y][x]);
        }
    }
    dfs(r + 1, c + 1, d);
    return 0;
}