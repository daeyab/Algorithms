import sys

n, m = list(map(int, sys.stdin.readline().split()))
arr = []
target = []
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().rstrip())))
for _ in range(n):
    target.append(list(map(int, sys.stdin.readline().rstrip())))

ans = 0
# 3*3 연산이 불가능한 경우에는 일치하는지만 보면 됨
if 3 <= n and 3 <= m:
    # 3*3의 영역을 만들 수 있는 좌표(맨 왼쪽 끝점) 기준 바꿔야한다면 교체
    # 이미 본 점은 다시 보지 않음
    #한번 바꾼 점을 다시 바꿔야 한다면 -> 본래 그대로의 값을 유지하게 됨
    # 그럼 애초에 바꾸는 것 자체가 성립이 되지 
    for y in range(n - 3 + 1):
        for x in range(m - 3 + 1):
            if arr[y][x] != target[y][x]:
                ans += 1
                for i in range(3):
                    for j in range(3):
                        if arr[y + i][x + j] == 1:
                            arr[y + i][x + j] = 0
                        else:
                            arr[y + i][x + j] = 1
        # print(arr)
if arr == target:
    print(ans)
else:
    print(-1)


