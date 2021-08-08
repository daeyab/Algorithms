import sys

n = int(input())
a_ls, b_ls, c_ls, d_ls = [], [], [], []
for _ in range(n):
    line = list(map(int, sys.stdin.readline().split()))
    a_ls.append(line[0])
    b_ls.append(line[1])
    c_ls.append(line[2])
    d_ls.append(line[3])

a_plus_b = {}
c_plus_d = {}

for a in a_ls:
    for b in b_ls:
        a_plus_b[a + b] = a_plus_b.get(a + b, 0) + 1


ans = 0
for c in c_ls:
    for d in d_ls:
        ans += a_plus_b.get(-c - d, 0)
print(ans)
