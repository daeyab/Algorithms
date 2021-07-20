num = int(input())
people = list(map(int, input().split()))
maxVal = -1
people.sort(reverse=True)
ans = 0
needMore = 0

for person in people:
    if needMore == 0:
        ans = ans + 1
        needMore = person - 1
    else:
        needMore = needMore - 1

print(ans)
