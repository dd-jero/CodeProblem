import sys

# 최장 공통부분 수열 => 문자 사이를 건너뛰어 공통되면서 가장 긴 부분 문자열 찾기 
def solution():
    LCS = [[0]*(m+1) for _ in range(n+1)]

    for i in range(1,n+1):
        for j in range(1,m+1):
            if first[i-1] == second[j-1]:
                LCS[i][j] = LCS[i-1][j-1]+1 # 두 문자가 같으면 지금까지 최대 공통 부분 수열에 1 더함 
            else:
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]) # 현재 문자를 비교하는 과정 이전의 과정들 비교 

    return LCS[-1][-1]

first = list(str(sys.stdin.readline().strip()))
second = list(str(sys.stdin.readline().strip()))
n,m = len(first),len(second)
print(solution())
