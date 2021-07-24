from collections import deque


def p(arr):
    for y in range(1, len(arr)):
        for x in range(1, len(arr)):
            print(arr[y][x], end=" ")
        print()


def met_body(y, x, q):
    if [y, x] in q:
        # print("MET BODY")
        return True
    return False


n = int(input())
arr = [[0] * (n + 1) for _ in range(n + 1)]
apple_num = int(input())
for _ in range(apple_num):
    y, x = map(int, input().split())
    arr[y][x] = 1
turn_cnt = int(input())
turns = []
for _ in range(turn_cnt):
    t, dir = input().split()
    turns.append([int(t), dir])
turns.sort()
turns = deque(turns)
movements = deque()
movements.append([1, 1])
# p(arr)
y, x, sec = 1, 1, 0
# 우 하 좌 상
dy, dx = [0, 1, 0, -1], [1, 0, -1, 0]
dir_index = 0
# p(arr)
while True:
    # print(sec, movements)
    # 그 다음 좌표
    ny, nx = y + dy[dir_index], x + dx[dir_index]
    # print(ny, nx, arr[ny][nx])
    # 좌표 검증
    if ny <= 0 or nx <= 0 or n < ny or n < nx or met_body(ny, nx, movements):
        sec += 1
        break
    if ny > 0 and ny <= n and nx > 0 and nx <= n and arr[ny][nx] != 1:
        movements.popleft()
    if ny > 0 and ny <= n and nx > 0 and nx <= n and arr[ny][nx] == 1:
        arr[ny][nx] = 0

    movements.append([ny, nx])
    # 사과를 만나면 그냥 헤드만 추가해줌
    y, x = ny, nx
    sec += 1
    if turns:
        turn_sec = turns[0][0]
    if sec == turn_sec:
        _, dir = turns.popleft()
        if dir == "D":
            dir_index = (dir_index + 1) % 4
        else:
            dir_index = (dir_index - 1) % 4

print(sec)

