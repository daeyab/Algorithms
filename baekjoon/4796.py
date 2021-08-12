import sys

i = 0
while True:
    i += 1
    available, total, vacation = list(map(int, sys.stdin.readline().split()))
    # print(available, total, vacation)
    if available == 0 and total == 0 and vacation == 0:
        break

    ans = available * (vacation // total)
    ans += min(available, vacation % total)
    print("Case " + str(i) + ": " + str(ans))

