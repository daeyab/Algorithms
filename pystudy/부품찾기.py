N = int(input())
every = list(map(int, input().split()))
M = int(input())
finds = list(map(int, input().split()))

for f in finds:
    if f in every:
        print("yes", end=" ")
    else:
        print("no", end=" ")
