# 참고 : http://wookje.dance/2017/02/20/boj-1300-K번째-수/

n = int(input())
m = int(input())


def cnt_lower(x):
    cnt = 0
    for i in range(1, n + 1):
        cnt += min(x // i, n)
    return cnt


s, e = 1, m
ans = 0
while s <= e:
    mid = (s + e) // 2
    if cnt_lower(mid) < m:
        s = mid + 1
    else:
        ans = mid
        e = mid - 1

print(ans)

