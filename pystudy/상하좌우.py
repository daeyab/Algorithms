n = int(input())
order = input().split()
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
move_types = ['L', 'R', 'U', 'D']
nx = 1
ny = 1

for o in order:
    for i in range(len(move_types)):
        if o == move_types[i]:
            if nx+dx[i] < 1 or nx+dx[i] > n or ny+dy[i] < 1 or ny+dy[i] > n:
                continue
            nx += dx[i]
            ny += dy[i]
print('%d %d' % (nx, ny))
