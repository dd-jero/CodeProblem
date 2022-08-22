from itertools import combinations
import sys

n = int(sys.stdin.readline())
t = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]
m = [i for i in range(n)]
mem = []
gap = 1899                                                                      # 19명*100 / 1명*1 일때 능력치 차이가 최대이므로 1900-1 = 1899

for i in range(1, n):                                                           # 두 팀의 수는 같지 않아도 되지만 최소 1명
    for team in list(combinations(m, i)):
        mem.append(list(team))

for i in range(len(mem)//2):                                                    # 예를 들어 총 4명일 때, 1번과 2,3,4번의 차이와 2,3,4번과 1번의 차이가 동일한 결과이기 때문에 효율적인 결과 출력을 위해 나누어 줌.
    stat_1 = 0
    team_1 = mem[i]
    
    for j in range(len(team_1)):
        member = team_1[j]

        for k in team_1:
            stat_1 += t[member][k]

    team_2 = mem[-i-1]
    stat_2 = 0

    for j in range(len(team_2)):
        member = team_2[j]

        for k in team_2:
            stat_2 += t[member][k]

    gap = min(gap, abs(stat_1-stat_2))

print(gap)


