n, m = map(int, input().split())

result = -1
for i in range(n):
    data = list(map(int, input().split()))
    result = max(result, min(data))

print(result)
