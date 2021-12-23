from sys import stdin
import sys
from itertools import  combinations
n = int(stdin.readline())
score = []
for i in range(n) :
    score.append(list(map(int, stdin.readline().split())))

teams = [i for i in range(1,n+1)]
team_combinations = list(combinations(teams,n//2))

# print(team_combinations)
min_val = sys.maxsize

for i in range(len(team_combinations)//2) :
    team_A = team_combinations[i]
    team_B = team_combinations[len(team_combinations)-i-1]
    A_combinations = list(combinations(team_A,2))
    B_combinations = list(combinations(team_B,2))
    # print (A_combinations)
    A_score, B_score = 0,0
    for i,j in A_combinations:
        A_score += score[i-1][j-1] + score[j-1][i-1]
    for i,j in B_combinations:
        B_score += score[i-1][j-1] + score[j-1][i-1]
    min_val = min(min_val, abs(A_score-B_score))
print(min_val)
# for teams in team_combinations:
