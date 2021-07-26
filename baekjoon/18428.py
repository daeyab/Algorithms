# 우선 장애물을 설치할 공간을 3군데 dfs
# 각 설치 구간바다 선생님을 기준으로 bfs
from itertools import combinations
from collections import deque
import copy

n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(str, input().split())))

empty, teachers = [], []
for y in range(n):
    for x in range(n):
        if arr[y][x] == "X":
            arr[y][x] = 0
            empty.append([y, x])
        elif arr[y][x] == "S":
            arr[y][x] = 1
        else:
            arr[y][x] = 2
            teachers.append([y, x])

# print(arr)

candidates = list(combinations(empty, 3))


def p(arr):
    print()
    for y in range(len(arr)):
        for x in range(len(arr[y])):
            print(arr[y][x], end=" ")
        print()
    print()


def check_if_not_meet(tmp):
    # 해당 배열에서 선생님에게 발각되는지 확인하는 함수
    # p(tmp)
    for teacher in teachers:
        ty, tx = teacher

        # 아래로 가는 경우
        tmp_y = ty
        while tmp_y < n and tmp[tmp_y][tx] != 3:
            if tmp[tmp_y][tx] == 1:
                return False
            tmp_y += 1
        tmp_y = ty
        while -1 < tmp_y and tmp[tmp_y][tx] != 3:
            if tmp[tmp_y][tx] == 1:
                return False
            tmp_y -= 1
        tmp_x = tx
        while tmp_x < n and tmp[ty][tmp_x] != 3:
            if tmp[ty][tmp_x] == 1:
                return False
            tmp_x += 1
        tmp_x = tx
        while -1 < tmp_x and tmp[ty][tmp_x] != 3:
            if tmp[ty][tmp_x] == 1:
                return False
            tmp_x -= 1

    return True


for c in candidates:
    tmp = copy.deepcopy(arr)
    for obs in c:
        ny, nx = obs
        tmp[ny][nx] = 3
    if check_if_not_meet(tmp):
        print("YES")
        quit()
print("NO")

# def dfs(n):
#     if n==3 :
#         # 선생님을 만나는지 확인하는 구간
#         pass
#     else :
#         for ny in range(n) :
#             for nx in range(n) :
#                 if arr[ny][nx] == 0 :

