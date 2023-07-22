import sys

def solution():

    dp = [[0]*(n+1) for _ in range(2)]
    
    for i in range(2):
        dp[i][1] = sticker[i][0] 

    for j in range(2, n+1):
        for i in range(2):
            if i % 2 == 0:
                dp[i][j] = max(dp[i+1][j-1],dp[i+1][j-2]) + sticker[i][j-1]
            else:
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j-2]) + sticker[i][j-1]

    return dp

t = int(sys.stdin.readline())

for _ in range(t):

    sticker = []
    n = int(sys.stdin.readline())

    for _ in range(2):
        sticker.append(list(map(int,sys.stdin.readline().split())))

    res = solution()

    result = 0
    for i in range(2):
        if result < res[i][n]:
            result = res[i][n]

    print(result)

