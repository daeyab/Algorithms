import sys

n = int(input())
alphabets = dict()
dic = dict()
ls = []
for _ in range(n):
    word = list(sys.stdin.readline().strip())
    ls.append(word)
    size = len(word)
    for i, w in enumerate(word):
        dic[w] = dic.get(w, 0) + pow(10, size - i - 1)

ttt = sorted(dic.items(), key=lambda x: x[1], reverse=True)

num = 9

for t in ttt:
    alphabets[t[0]] = num
    num -= 1
# dic = list(dic.sort(lambda x: x[1], reverse=True))

final = []
for w in ls:
    tmp = ""
    for x in w:
        tmp += str(alphabets[x])
    final.append(int(tmp))
print(sum(final))

# print(ls)

