import sys
from collections import deque

def solution(N,K,cnt):
    
    q = deque()
    q.append([N,cnt])
    visited[N] = 1

    while q:
        cur_index, cur_cnt = q.popleft()

        # 동생의 위치에 도달하면 동생을 찾는게 걸린 cnt 삽입
        if cur_index == K:              
            cnt_list.append(cur_cnt)

        for dcur in dx:
            # 1초 후 2*X 위치
            if dcur == 2:    
                nxt_index = cur_index * dcur
            # 1초 후 X-1 또는 X+1 위치 
            else:              
                nxt_index = cur_index + dcur

            # 해당 범위 내에 존재하고 방문하지 않았으면 
            if 0 <= nxt_index < 100001 and not visited[nxt_index]: 
                q.append([nxt_index, cur_cnt + 1])
                visited[nxt_index] = 1
        
def main():
    global visited, cnt_list,dx

    N,K = map(int, sys.stdin.readline().split())

    dx = [2, 1, -1]
    visited = [0 for _ in range(100001)]
    cnt = 0
    cnt_list = []

    solution(N,K,cnt)
    print(min(cnt_list))

if __name__ == "__main__":
    main()
