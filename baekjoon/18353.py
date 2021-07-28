n = int(input())
ls = list(map(int, input().split()))
dp = [0] * n

for i in range(n - 1, -1, -1):
    val = ls[i]
    max_val = 0
    for j in range(i + 1, n):
        if val > ls[j]:
            max_val = max(max_val, dp[j])
    dp[i] = max_val + 1

print(n - max(dp))

