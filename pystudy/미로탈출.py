from collections import deque

queue = deque()
n,m = map(int, input().split())
visited = [[False]* (m) for _ in range(n)]

arr = []
for _ in range(n) :
    arr.append(list(map(int, input())))

def bfs(sy, sx) :
    dx = [0, 0,-1,1]
    dy = [1,-1,0, 0]
    queue.append([sy,sx,1])
    while queue :
        first = queue.popleft()
        y = first[0]
        x = first[1]
        dist = first[2]
        visited[y][x] = True
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if ny > -1 and ny < n and nx > -1 and nx < m and not visited[ny][nx] and arr[ny][nx] == 1 :
                if ny == n-1 and nx == m-1 :
                    return (dist + 1) 
                else :
                    queue.append([ny,nx,dist+1])

print(bfs(0,0))