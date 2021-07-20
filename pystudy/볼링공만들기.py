n, m = map(int, input().split())
balls = list(map(int, input().split()))

ans = 0
for i in range(len(balls)):
    for j in range(i + 1, len(balls)):
        if balls[i] != balls[j]:
            ans += 1
print(ans)
