n, m = map(int, input().split())
arr = []

#
for _ in range(n):
    arr.append(list(map(int, input())))

visited = [[False]*m for i in range(n)]

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def dfs(y, x):
    if not visited[y][x]:
        visited[y][x] = True
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if nx < 0 or m <= nx or ny < 0 or n <= ny:
                continue
            if(arr[ny][nx] == 0 and not visited[ny][nx]):
                dfs(ny, nx)


cnt = 0
for y in range(n):
    for x in range(m):
        if arr[y][x] == 0 and not visited[y][x]:
            dfs(y, x)
            cnt += 1

print(cnt)
