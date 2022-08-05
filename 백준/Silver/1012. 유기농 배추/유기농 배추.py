from collections import deque

def find_min(i,j):
    count = 1
    deq = deque()
    deq.append([i,j])

    while deq:
        r,c = deq.popleft()

        for dx, dy in dxy:                                                      # 상하좌우 좌표 확인
            nx = r + dx
            ny = c + dy

            if 0 <= nx < n and 0 <= ny < m and ground[nx][ny] == 1:             # 인접 좌표가 범위 안에 속하고 요소가 1이면
                deq.append([nx,ny])                                             # deq에 인접 좌표 추가
                ground[nx][ny] = 0                                              # 요소 0으로 초기화
                count += 1
    return count

t = int(input())

dxy = [[1,0], [-1,0],[0,1],[0,-1]]

for _ in range(t):
    cnt = []

    m,n,k = map(int,input().split())
    ground = [[0]*m for _ in range(n)]                                          # 배추밭 형성

    for _ in range(k):
        y,x = map(int,input().rstrip().split())
        ground[x][y] = 1                                                        # 해당 좌표의 요소를 1로 초기화


    for i in range(n):                  
        for j in range(m):
            if ground[i][j] == 1:                                               # 좌표의 요소가 1일 때                                                            
                cnt.append(find_min(i,j))                                       # BFS의 리턴 값을 리스트에 추가 
                
    print(len(cnt))                                                             # cnt의 개수가 덩어리의 개수(필요한 지렁이 개수)
        
