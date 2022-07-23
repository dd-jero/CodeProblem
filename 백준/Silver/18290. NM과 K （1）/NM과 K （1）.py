import sys

def select(row, column, cnt, sum_val):
    global res
    side = [[-1, 0], [1, 0], [0, -1], [0, 1]]                           # 인접한 칸 확인을 위한 리스트 
    if  cnt == k:                                                       # K칸 선택이 끝나면 (종료를 위한 조건문)
        res = max(res, sum_val)                                         # 최대 값을 출력하도록
        return 

    for i in range(row, n):
        for j in range(column if row == i else 0, m):
                if visited[i][j]:                                       # 현재칸을 선택 했었으면 
                    continue

                for x1,y1 in side:                                      # 인접 칸 리스트 이용
                    x2, y2 = i + x1, j + y1
                    if 0 <= x2 < n and 0 <= y2 < m and visited[x2][y2]: # 해당 범위에 들고, 선택 했었스면
                        break                                           # 가지치기
                
                else:                                                   # 현재칸을 선택하지 않았으면 
                    visited[i][j] = True                                # 현재 칸의 상태 변화
                    select(i,j,cnt+1,sum_val+list_nm[i][j])             # 재귀
                    visited[i][j] = False 

n,m,k = map(int,sys.stdin.readline().split())

visited = [[False] * m for _ in range(n)]                               # False를 요소로 가진 n x m 행렬

list_nm = []
res = -1000000                                                          # 10*10*(-10000) : 최소 수와 최대 선택으로 나올 수 있는 더한 값

for _ in range(n):
    list_nm.append(list(map(int,input().split())))

select(0,0,0,0)                                                         # [0,0]에서 부터 시작
print(res)
