from itertools import combinations
import sys

n = int(sys.stdin.readline())
t = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]
m = [i for i in range(n)]
mem = []
gap = 200

for team in list(combinations(m, n//2)):
    mem.append(team)


for i in range(len(mem)//2):
    stat_1 = 0
    team_1 = mem[i]
    for j in range(n//2):
        member = team_1[j]

        for k in team_1:
            stat_1 += t[member][k]

    team_2 = mem[-i-1]
    stat_2 = 0

    for j in range(n//2):
        member = team_2[j]

        for k in team_2:
            stat_2 += t[member][k]

    gap = min(gap, abs(stat_1-stat_2))


print(gap)
