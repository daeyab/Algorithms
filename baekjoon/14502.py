import sys
from collections import deque
from itertools import combinations
import copy

n, m = map(int, sys.stdin.readline().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

virus = []
empty = []

for y in range(n):
    for x in range(m):
        if arr[y][x] == 2:
            virus.append([y, x])
        elif arr[y][x] == 0:
            empty.append([y, x])

walls = list(combinations(empty, 3))


def p(a):
    print("--------------------------------")
    for y in range(len(a)):
        for x in range(len(a[0])):
            print(a[y][x], end=" ")
        print()


def bfs(arr, y, x):
    visited = [[False] * m for _ in range(n)]
    q = deque()
    q.append([y, x])
    dy, dx = [0, 1, 0, -1], [1, 0, -1, 0]
    height = len(arr)
    width = len(arr[0])
    while q:
        now = q.popleft()
        now_y, now_x = now
        visited[now_y][now_x] = True
        for i in range(4):
            next_y = now_y + dy[i]
            next_x = now_x + dx[i]
            if (
                next_y >= 0
                and next_x >= 0
                and next_y < height
                and next_x < width
                and visited[next_y][next_x] == False
                and arr[next_y][next_x] == 0
            ):
                arr[next_y][next_x] = 2
                q.append([next_y, next_x])
    return arr


def solve(wall, virus, arr):
    tmp = copy.deepcopy(arr)
    for w in wall:
        y, x = w
        tmp[y][x] = 1
    # print(wall)
    # p(tmp)
    for v in virus:
        y, x = v
        tmp = bfs(tmp, y, x)
    ans = []
    cnt = 0
    for y in range(len(tmp)):
        for x in range(len(tmp[0])):
            if tmp[y][x] == 0:
                cnt += 1
    ans.append(cnt)
    return max(ans)
    # print(tmp)


res = []
for wall in walls:
    res.append(solve(wall, virus, arr))

print(max(res))

