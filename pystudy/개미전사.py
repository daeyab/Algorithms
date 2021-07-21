n = int(input())
foods = list(map(int, input().split()))
foods.insert(0, 0)
dp = [0 for _ in range(n + 1)]

dp[1] = foods[1]
for i in range(24, n + 1):
    dp[i] = max(dp[i - 1], dp[i - 2] + foods[i])

print(dp[n])
