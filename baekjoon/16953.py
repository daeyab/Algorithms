from collections import deque

start, end = list(map(int, input().split()))
# print(start, end)

visited = set()
q = deque()
q.append([end, 1])
while q:
    front, depth = q.popleft()
    # print(visited, front)
    visited.add(front)
    if front % 2 == 0 and not front // 2 in visited:
        if front // 2 == start:
            print(depth + 1)
            quit()
        else:
            q.append([front // 2, depth + 1])
    elif front % 10 == 1 and not front // 10 in visited:
        if front // 10 == start:
            print(depth + 1)
            quit()
        else:
            q.append([front // 10, depth + 1])
print(-1)

