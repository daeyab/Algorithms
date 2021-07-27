import sys

n, c = map(int, sys.stdin.readline().split())

houses = []
for _ in range(n):
    house = int(input())
    houses.append(house)
houses.sort()

s = 1
e = houses[-1] - houses[0]
result = 0

while s <= e:
    mid = (s + e) // 2
    value = houses[0]
    count = 1

    for i in range(1, n):
        if houses[i] >= value + mid:
            value = houses[i]
            count += 1
    if count >= c:
        s = mid + 1
        result = mid
    else:
        e = mid - 1

print(result)

