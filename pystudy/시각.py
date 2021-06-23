n = int(input())
h = 0
m = 0
s = 0
cnt = 0


def checkHas3():
    if h % 10 == 3 or h//10 == 3 or m % 10 == 3 or m//10 == 3 or s % 10 == 3 or s//10 == 3:
        return True
    else:
        return False


while h <= n:
    s += 1
    if s == 60:
        s = 0
        m += 1
        if m == 60:
            m = 0
            h += 1
    if checkHas3():
        cnt += 1


print(cnt)
