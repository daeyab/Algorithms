import sys

n = int(sys.stdin.readline())
ls = list(map(int, sys.stdin.readline().split()))

ls.sort()
j = n - 1
i = 0
min_val = 2000000000
ans = []
while i < j:
    mixed = ls[i] + ls[j]
    if abs(mixed) < min_val:
        min_val = abs(mixed)
        ans.clear()
        ans = [ls[i], ls[j]]
    if mixed == 0:
        break
    if mixed > 0:
        j -= 1
    else:
        i += 1
print(*ans)

