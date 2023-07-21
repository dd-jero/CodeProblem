import sys

def solution():

    for i in range(1,n+1):
        for j in range(1,n+1):
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + graph[i][j]
         
def main():
    global n, dp, graph
    n,m = map(int,sys.stdin.readline().split())
    graph = [[0] + list(map(int,sys.stdin.readline().split())) for _ in range(n)]

    dp = [[0]*(n+1) for _ in range(n+1)]
    graph = [[0]*(n+1)] + graph
    dp[1][1] = graph[1][1]

    solution()
    
    for _ in range(m):
        x1,y1,x2,y2 = map(int,sys.stdin.readline().split())
        print(dp[x2][y2] - dp[x2][y1-1] -dp[x1-1][y2] + dp[x1-1][y1-1])
        
        
if __name__ == "__main__":
    main()
    