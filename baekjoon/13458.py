from sys import stdin
import math
classroom_num = int(stdin.readline())
classrooms = list(map(int, stdin.readline().split()))
head, sub = map(int, stdin.readline().split())
ans = 0
for students in classrooms:
    ans += 1
    if students - head > 0 :
        ans += math.ceil((students - head) / sub )

print(ans)

# print(classrooms)