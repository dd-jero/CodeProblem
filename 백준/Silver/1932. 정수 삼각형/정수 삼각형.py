import sys

def solution(n,triangle,dp):
    for i in range(1,n):
        for j in range(len(triangle[i])):
            if j == len(triangle[i]) - 1:
                dp[i][j] = dp[i-1][j-1] + triangle[i][j]
            else:
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j]

def main():
    n = int(sys.stdin.readline())
    triangle = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]

    dp = [[0]*n for _ in range(n)]
    dp[0][0] = triangle[0][0]

    solution(n,triangle,dp)
    print(max(dp[-1]))

if __name__ == "__main__":
    main()
