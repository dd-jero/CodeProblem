dp = [0] * 1001
dp[1] = 1
dp[2] = 2

n = int(input())

for i in range(3, n+1):                             
    dp[i] = (dp[i-1] + dp[i-2]) % 10007         # 점화식을 이용한 가능 개수 구하기 

print(dp[n])
