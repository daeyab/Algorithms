n, m = map(int, input().split())
y, x, dir = map(int, input().split())  # location and direction

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))

cnt = 1
isFinished = False
arr[y][x] = -1
while True:
    # 순회 알고리즘 적용
    for i in range(4):
        dir = (dir-1) % 4
        nx = x + dx[dir]
        ny = y + dy[dir]
        if 0 <= nx and 0 <= ny and nx < m and ny < n:
            if arr[ny][nx] == 0:
                cnt += 1
                arr[ny][nx] = -1
                x = nx
                y = ny
                break
        if i == 3:
            if arr[ny-dy[dir]][nx-dx[dir]] < 1:
                x = nx-dy[dir]
                y = ny-dx[dir]
                break
            else:
                isFinished = True

    # 빠져 나오는 거 적용
    if isFinished:
        break
    # 그래도 안된다면 종료


print(cnt)
