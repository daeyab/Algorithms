from collections import deque
import sys

n, k = map(int, sys.stdin.readline().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))
s, final_y, final_x = map(int, sys.stdin.readline().split())
# print(arr)

virus = []
for y in range(len(arr)):
    for x in range(len(arr[0])):
        if arr[y][x] != 0:
            virus.append([arr[y][x], y, x])

for v in virus:
    v.append(0)
virus.sort(key=lambda x: x[0])
# print(virus)


def p(arr):
    print("-")
    for y in range(len(arr)):
        for x in range(len(arr[0])):
            print(arr[y][x], end=" ")
        print()


dy, dx = [0, 1, 0, -1], [1, 0, -1, 0]
q = deque(virus)
# t = 0
while q:
    v, y, x, t = q.popleft()
    # print(str(y), str(x) + "차례")
    if s <= t:
        break
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if -1 < ny and -1 < nx and ny < n and nx < n and arr[ny][nx] == 0:
            arr[ny][nx] = v
            q.append([v, ny, nx, t + 1])
        # print(q)
    # t += 1
    # print(t)
    # p(arr)
if arr[final_y - 1][final_x - 1] == 0:
    print(0)
else:
    print(arr[final_y - 1][final_x - 1])

