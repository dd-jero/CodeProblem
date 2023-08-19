import sys

dp = [[0]*3 for _ in range(100001)]
dp[0] = [0,0,0] # 1로 끝나는 개수, 2로 끝나는 개수, 3으로 끝나는 개수로 나눔
dp[1] = [1,0,0]
dp[2] = [0,1,0]
dp[3] = [1,1,1]

for i in range(4,100001):
    dp[i][0] = (dp[i-1][1]%1000000009 + dp[i-1][2]%1000000009)
    dp[i][1] = (dp[i-2][0]%1000000009 + dp[i-2][2]%1000000009)
    dp[i][2] = (dp[i-3][0]%1000000009 + dp[i-3][1]%1000000009)

t = int(sys.stdin.readline().strip())

for _ in range(t):
    num = int(sys.stdin.readline().strip())
    print(sum(dp[num])%1000000009)