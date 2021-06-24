loc = input()

y = int(loc[1])
x = ord(loc[0])-ord('a')+1

steps = [[2, 1], [2, -1], [1, 2], [1, -2],
         [-1, 2], [-1, -2], [-2, 1], [-2, -1]]

cnt = 0
for s in steps:
    if y+s[0] < 1 or y+s[0] > 8 or x+s[1] < 1 or x+s[1] > 8:
        continue
    cnt += 1

print(cnt)
