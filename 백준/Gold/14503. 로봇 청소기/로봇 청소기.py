import sys

# dfs 
def solution(i,j,direction):
    global cnt
    if room[i][j] == 0 and not visited[i][j]:
        cnt += 1
        visited[i][j] = 1

    d = direction # 현재 방향을 계속해서 업데이트 하기 위함
    for _ in range(4): # 현재 방향에서 왼쪽방향부터 확인 

        d = (d+3)%4
        dx, dy = dxy[d]
        next_x = i + dx
        next_y = j + dy

        if room[next_x][next_y] == 0:
            if not visited[next_x][next_y]: # 왼쪽방향에 아직 청소하지 않은 공간이 있어 회전한 다음 전진 
                solution(next_x,next_y,d)
                    
    # 네 방향 모두 청소되있거나 벽인 경우
    back = (d+2)%4
    dx, dy = dxy[back] 
    nxt_x = i + dx
    nxt_y = j + dy

    if room[nxt_x][nxt_y] == 0: # 뒤 칸이 벽이 아님

        solution(nxt_x,nxt_y,d) # 바라 보는 방향 유지한 채로 한칸 후진 
    else:   # 뒤 칸이 벽이라 작동 멈춤
        print(cnt)
        exit()

N,M = map(int, sys.stdin.readline().split())
start_x, start_y, start_dir = map(int, sys.stdin.readline().split())
room = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

visited = [[0 for _ in range(M)] for _ in range(N)]
dxy = [(-1,0),(0,1),(1,0),(0,-1)] # 북동남서
cnt = 0
solution(start_x,start_y,start_dir)

