n, m = map(int, input().split())
cakes = list(map(int, input().split()))
left, ans, mid, right = 0, 0, 0, max(cakes)
# print(cakes)
while left <= right:
    mid = (left + right) // 2
    rest = 0
    # print(mid, end=" ->")
    for c in cakes:
        # print("mid")
        if mid < c:
            rest += c - mid
    # print(rest)
    if m <= rest:
        left = mid + 1
        ans = mid

    else:
        right = mid - 1


print(ans)
