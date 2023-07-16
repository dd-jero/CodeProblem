import sys

def solution():

    for i in range(1, n):
        for j in range(3):
            # i번 집은 i-1, i+1 번 집의 색과 달라야 하기 때문에 이전 행에서 해당 인덱스의 비용은 배제하여 비교
            dp[i][j] = min([c for idx, c in enumerate(dp[i-1]) if idx != j]) + cost[i][j] 
           
    return min(dp[n-1]) # dp 리스트의 마지막 행의 최소 값이 모든 집을 칠하는 비용의 최고 값임

n = int(sys.stdin.readline())
cost = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
dp = [cost[0]] + [[0]*3 for _ in range(n-1)]
print(solution())