import heapq

n = int(input())


heap = []
for _ in range(n):
    data = int(input())
    heapq.heappush(heap, data)

ans = 0

while len(heap) > 1:
    first = heapq.heappop(heap)
    second = heapq.heappop(heap)
    sum_val = first + second
    ans += sum_val
    heapq.heappush(heap, sum_val)


print(ans)

