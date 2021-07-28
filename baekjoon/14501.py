n = int(input())
times = []
payments = []
dp = [0] * n
for _ in range(n):
    t, p = map(int, input().split())
    times.append(t)
    payments.append(p)
dp.append(0)
for i in range(n - 1, -1, -1):
    if i + times[i] > n:
        dp[i] = dp[i + 1]
    else:
        dp[i] = max(dp[i + 1], dp[i + times[i]] + payments[i])
print(dp[0])

