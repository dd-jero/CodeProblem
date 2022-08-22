from itertools import combinations
import sys

n = int(sys.stdin.readline())                                               # 한 팀의 멤버 수 
t = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]         # 능력치 리스트
m = [i for i in range(n)]                                                   # 팀 구성을 위한 번호 리스트 
mem = []
gap = 200

for team in list(combinations(m, n//2)):                                    # 요소를 활용하기 위해 가능한 팀의 조합을 구성 (combinations 함수를 이용하여 서로 다른 수를 조합)
    mem.append(team)

for i in range(len(mem)//2):
    
    stat_1 = 0
    stat_2 = 0
    team_1 = mem[i]                                                         # 첫 팀은 리스트의 처음부터 
    team_2 = mem[-i-1]                                                      # 두 번쨰 팀은 리스트의 마지막부터 
    
    for j in range(n//2):
        member = team_1[j]

        for k in team_1:                            
            stat_1 += t[member][k]                                          # 요소로 활용하여 첫 팀의 능력치 구하기 

    for j in range(n//2):
        member = team_2[j]

        for k in team_2:
            stat_2 += t[member][k]                                          # 요소로 활용하여 두 번째 팀의 능력치 구하기 

    gap = min(gap, abs(stat_1-stat_2))                                      # min 함수로 최솟값 구하기 

print(gap)
