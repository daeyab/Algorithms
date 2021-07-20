num = int(input())
coins = list(map(int, input().split()))
coins.sort()

ans = 1
for coin in coins:
    if ans < coin:
        break
    ans += coin

print(ans)
