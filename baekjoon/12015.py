import sys
from bisect import bisect_left

n = int(input())
ls = list(map(int, sys.stdin.readline().split()))

dp = [0]

def get_left(dp, num):
    l, r = 0, len(dp) - 1
    while l < r:
        mid = (r + l) // 2
        if dp[mid] < num:
            l = mid + 1
        else:
            r = mid
    return l


for num in ls:
    if dp[-1] < num:
        dp.append(num)
    else:
        # dp[bisect_left(dp, num)] = num
        dp[get_left(dp, num)] = num
print(len(dp) - 1)



