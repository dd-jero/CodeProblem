from collections import deque
T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
dxy = [(0,1), (0,-1), (1,0), (-1,0)]

def bfs():
    deq = deque()
    deq.append((0,0))
    visited[0][0] = True
    res = [[0] * N for _ in range(N)] 
    
    while deq:
        x,y = deq.popleft()

        for dx, dy in dxy:
            nxt_x = x+dx
            nxt_y = y+dy

            if 0<=nxt_x<N and 0<=nxt_y<N:

                if not visited[nxt_x][nxt_y]:
                    res[nxt_x][nxt_y] = int(res[x][y]) + int(road[nxt_x][nxt_y])
                    deq.append((nxt_x,nxt_y))
                    visited[nxt_x][nxt_y] = True
                else:
                    if res[x][y] + int(road[nxt_x][nxt_y]) < res[nxt_x][nxt_y]:
                        res[nxt_x][nxt_y] = res[x][y] + int(road[nxt_x][nxt_y])
                        deq.append((nxt_x,nxt_y))
    return res[N-1][N-1]
                        
for test_case in range(1, T + 1):
    # ///////////////////////////////////////////////////////////////////////////////////
    N = int(input())
    visited = [[False]*N for _ in range(N)]
    
    road = [list(str(input())) for _ in range(N)]
        
    ans = bfs()
    print(f"#{test_case} {ans}")

    # ///////////////////////////////////////////////////////////////////////////////////
