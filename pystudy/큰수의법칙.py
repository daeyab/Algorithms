n, m, k = map(int, input().split())
ls = list(map(int, input().split()))

ls.sort(reverse=True)

biggest = ls[0]
second = ls[1]

print((m/(k+1))*(k*biggest+second) + ((m % (k+1))*biggest))
