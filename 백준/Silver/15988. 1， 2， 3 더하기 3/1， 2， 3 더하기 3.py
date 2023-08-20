import sys

dp = [0,1,2,4] +[0]*999997
t = int(sys.stdin.readline().strip())

for i in range(4,1000001):
    dp[i] = (dp[i-1]%1000000009 + dp[i-2]%1000000009 + dp[i-3]%1000000009)%1000000009

for _ in range(t):
    num = int(sys.stdin.readline().strip())
    print(dp[num])