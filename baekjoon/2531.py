import sys

# 접시 수, 초밥 수, 연속 초밥 수, 쿠폰
n, d, k, c = map(int, sys.stdin.readline().split())

arr = []
for _ in range(n):
    arr.append(int(input()))
arr += arr
ans = 0
for i in range(n):
    candidate = set(arr[i : i + k])
    if not c in candidate:
        candidate.add(c)
    ans = max(ans, len(candidate))
print(ans)

