import sys

def solution():
    for i in range(1,n+1):
        for j in range(k+1):

            if j < product[i-1][0]:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-product[i-1][0]]+product[i-1][1])

    return dp[-1][-1]

product = []
n,k = map(int,sys.stdin.readline().split())
dp = [[0]*(k+1) for _ in range(n+1)]

for _  in range(n):
    product.append(list(map(int,sys.stdin.readline().split())))

print(solution())

