import sys

doc = list(sys.stdin.readline().strip())
word = list(sys.stdin.readline().strip())
# print(doc, word)

i = 0
ans = 0
while i < (len(doc) - len(word) + 1):
    if doc[i : i + len(word)] == word:
        ans += 1
        i = i + len(word)
    else:
        i += 1
print(ans)

