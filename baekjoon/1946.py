import sys

tc = int(sys.stdin.readline())
for _ in range(tc):
    n = int(input())
    rank = []
    for _ in range(n):
        rank.append(list(map(int, sys.stdin.readline().strip().split())))
    rank.sort(key=lambda x: x[0])

    tmp = 100001
    ans = 0
    for r1, r2 in rank:
        if r2 < tmp:
            ans += 1
            tmp = r2

    print(ans)

