import sys

n = int(input())
prices = list(map(int, sys.stdin.readline().split()))
budget = int(input())
s, e = 0, max(prices)

# final answer
ans = 0
# tmp for saving budget
tmp_budget = 0

while s <= e:
    mid = (s + e) // 2
    tmp_budget = 0
    max_price = mid
    for price in prices:
        if mid < price:
            tmp_budget += mid
            max_price = max(max_price, mid)
        else:
            tmp_budget += price

    if tmp_budget <= budget:

        ans = max(max_price, ans)
        s = mid + 1
    else:
        e = mid - 1

print(ans)

