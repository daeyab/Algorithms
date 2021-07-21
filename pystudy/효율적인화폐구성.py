import sys

MAX_INT = sys.maxsize
n, goal = map(int, input().split())
coins = []
dp = [MAX_INT for _ in range(100001)]
for _ in range(n):
    coins.append(int(input()))

# print(len(dp))
for c in coins:
    print(c)
    dp[c] = 1

for i in range(goal + 1):
    # print(i)
    for c in coins:
        # print(c)
        if i - c > -1 and dp[i - c] != MAX_INT:
            dp[i] = min(dp[i - c] + 1, dp[i])
if dp[goal] == MAX_INT:
    dp[goal] = -1
print(dp[goal])
