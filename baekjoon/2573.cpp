#include <bits/stdc++.h>

using namespace std;

int n, m, maxH = -1;
int arr[302][302];
bool visited[302][302];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void decreaseHeight() {
    int tmpArr[302][302];
    memcpy(tmpArr, arr, sizeof(arr));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX > -1 && newX < m && newY > -1 && newY < n &&
                    arr[newY][newX] < 1)
                    tmpArr[y][x]--;
            }
        }
    }
    memcpy(arr, tmpArr, sizeof(arr));
}

void dfs(int y, int x) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX > 0 && newX < m && newY > 0 && newY < n &&
            arr[newY][newX] > 0 && !visited[newY][newX])
            dfs(newY, newX);
    }
}

int countGroups() {
    memset(visited, false, sizeof(visited));
    int groupCnt = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (arr[y][x] > 0 && !visited[y][x]) {
                groupCnt++;
                dfs(y, x);
            }
        }
    }
    return groupCnt;
}

bool isAllMelted() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (arr[y][x] > 0) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (y == 0 || y == n - 1 || x == 0 || x == m - 1) arr[y][x] = 0;
            scanf("%d", &arr[y][x]);
            maxH = max(maxH, arr[y][x]);
        }
    }

    for (int i = 0;; i++) {
        if (isAllMelted()) {
            printf("0\n");
            break;
        }

        if (i > 0) decreaseHeight();
        int ans = countGroups();
        // printf("%d : %d\n", i, ans);
        if (ans > 1) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}