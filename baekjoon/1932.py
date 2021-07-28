n = int(input())
arr, dp = [], []

for i in range(1, n + 1):
    arr.append(list(map(int, input().split())))
    dp.append([0] * i)

dp[0][0] = arr[0][0]
for y in range(1, n):
    for x in range(y + 1):
        if x == 0:
            dp[y][x] = dp[y - 1][x] + arr[y][x]
        elif x == y:
            dp[y][x] = dp[y - 1][x - 1] + arr[y][x]
        else:
            dp[y][x] = max(dp[y - 1][x - 1], dp[y - 1][x]) + arr[y][x]
print(max(dp[n - 1]))

