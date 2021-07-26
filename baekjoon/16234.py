from collections import deque
import math


def p(arr):
    print()
    for y in range(n):
        for x in range(n):
            print(arr[y][x], end=" ")
        print()


n, l, r = map(int, input().split())
arr = []
group = []
for i in range(n):
    arr.append(list(map(int, input().split())))
    group.append([0] * n)

dy, dx = [0, 1, 0, -1], [1, 0, -1, 0]

group_num = 0
group_dict = {}


time = 0
has_change = True


def bfs(y, x):
    global group_num, group, arr
    q = deque()
    q.append([y, x])
    while q:
        ny, nx = q.popleft()
        group[ny][nx] = group_num
        for i in range(4):
            next_y = ny + dy[i]
            next_x = nx + dx[i]

            if (
                -1 < next_x
                and -1 < next_y
                and next_x < n
                and next_y < n
                and group[next_y][next_x] == 0
                and l <= abs(arr[ny][nx] - arr[next_y][next_x])
                and abs(arr[ny][nx] - arr[next_y][next_x]) <= r
            ):
                group[next_y][next_x] = group_num
                q.append([next_y, next_x])
                global has_change
                has_change = True


while True:
    has_change = False
    group_num = 0
    group_dict = {}
    group.clear()
    for i in range(n):
        group.append([0] * n)
    for y in range(n):
        for x in range(n):
            if group[y][x] == 0:
                group_num += 1
                bfs(y, x)
    for y in range(n):
        for x in range(n):
            if str(group[y][x]) in group_dict:
                group_dict[str(group[y][x])].append([y, x])
            else:
                group_dict[str(group[y][x])] = [[y, x]]
    for d in group_dict:
        group_list = list((group_dict[d]))
        sum_of_group = 0
        for c in group_list:
            sum_of_group += arr[c[0]][c[1]]
        for c in group_list:
            arr[c[0]][c[1]] = int(sum_of_group / len(group_list))
    if not has_change:
        break
    time += 1
print(time)

