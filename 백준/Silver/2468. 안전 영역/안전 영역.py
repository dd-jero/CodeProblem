import sys
from collections import deque

def solution(i,j,height):

    stack = deque()

    stack.append([i,j])
    visited[i][j] = 1
    
    while stack:
        x,y = stack.pop()

        for dx, dy in dxy:
            next_x = x + dx
            next_y = y + dy
            
            if 0 <= next_x < N and 0 <= next_y < N and not visited[next_x][next_y]:
                if region[next_x][next_y] > height:
                    visited[next_x][next_y] = 1
                    stack.append([next_x,next_y])

def main():
    
    global visited, dxy, region, N
    
    N = int(sys.stdin.readline())
    region = []
    max_height = 0
    res = 0

    dxy = [(0,-1), (1,0), (0,1), (-1,0)]

    for i in range(N):
        region.append(list(map(int, sys.stdin.readline().split())))

        if max_height < max(region[i]):
            max_height = max(region[i])

    for i in range(max_height+1):
        
        visited = [[0 for _ in range(N)]for _ in range(N)]
        cnt = 0
        
        for j in range(N):
            for k in range(N):
                if region[j][k] > i and not visited[j][k]:
                    solution(j,k,i)
                    cnt += 1
        if res < cnt:
            res = cnt
            
    print(res)
    
if __name__ == "__main__":
    main()
