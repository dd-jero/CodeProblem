n = int(input())
list_tp = [list(map(int,input().split())) for _ in range(n)]
dp = [0 for _ in range(n+1)]

for i in range(n):
    for j in range(i + list_tp[i][0], n+1):
        if dp[j] < dp[i] + list_tp[i][1]:
            dp[j] = dp[i] + list_tp[i][1]

print(dp[-1])        
