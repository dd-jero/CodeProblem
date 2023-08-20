import sys

dp = [0,1,2,2,3,3,6] + [[0] for _ in range(999995)]

t = int(sys.stdin.readline().strip())

for i in range(7,100001):
    dp[i] = (dp[i-2]%1000000009 + dp[i-4]%1000000009 + dp[i-6]%1000000009)%1000000009

for _ in range(t):
    num = int(sys.stdin.readline().strip())
    print(dp[num])