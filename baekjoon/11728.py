import sys

len1, len2 = map(int, sys.stdin.readline().split())
arr1 = list(map(int, sys.stdin.readline().split()))
arr2 = list(map(int, sys.stdin.readline().split()))

i, j = 0, 0
ans = []
while not (i == len1 and j == len2):
    if i == len1:
        ans.append(arr2[j])
        j += 1
    elif j == len2:
        ans.append(arr1[i])
        i += 1
    elif arr1[i] <= arr2[j]:
        ans.append(arr1[i])
        i += 1
    elif arr2[j] < arr1[i]:
        ans.append(arr2[j])
        j += 1

for num in ans:
    print(num, end=" ")

