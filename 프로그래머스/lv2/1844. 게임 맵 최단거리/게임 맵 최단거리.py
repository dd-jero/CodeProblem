from collections import deque

def solution(maps):
    visited = [[0 for _ in range(len(maps[0]))]for _ in range(len(maps))]
    dxy = [(1,0),(0,1),(-1,0),(0,-1)]
    answer = -1
    q = deque()
    q.append([0,0,1])
    visited[0][0] = 1

    while q:
        x,y,cnt = q.popleft()
        
        if x == len(maps)-1 and y == len(maps[0])-1:
            answer = cnt
            break
        
        for dx, dy in dxy:
            nxt_x = x + dx
            nxt_y = y + dy
            
            if 0<=nxt_x<len(maps) and 0<=nxt_y<len(maps[0]):
                if not visited[nxt_x][nxt_y] and maps[nxt_x][nxt_y] == 1:
                    q.append([nxt_x,nxt_y,cnt+1])
                    visited[nxt_x][nxt_y] = 1
    
    return answer


