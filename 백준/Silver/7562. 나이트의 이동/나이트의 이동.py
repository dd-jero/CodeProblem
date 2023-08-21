import sys
from collections import deque

def solution(i,j):

    q = deque()
    q.append([i,j,0])
    visited[i][j] = True

    while q:
        x,y,cnt = q.popleft()
        
        if x == want_x and y == want_y:
            return cnt

        for dx, dy in dxy:
            nxt_x = x + dx
            nxt_y = y + dy

            if 0 <= nxt_x < l and 0 <= nxt_y < l and not visited[nxt_x][nxt_y]:
                q.append([nxt_x,nxt_y,cnt+1])
                visited[nxt_x][nxt_y] = True

t = int(sys.stdin.readline().strip())

dxy = [(-2,-1),(-1,-2),(1,-2),(2,-1),(2,1),(1,2),(-1,2),(-2,1)]

for _ in range(t):
    l = int(sys.stdin.readline().strip())
    visited = [[False]*l for _ in range(l)]

    cur_x, cur_y = map(int,sys.stdin.readline().strip().split())
    want_x, want_y = map(int,sys.stdin.readline().strip().split())
    print(solution(cur_x, cur_y))