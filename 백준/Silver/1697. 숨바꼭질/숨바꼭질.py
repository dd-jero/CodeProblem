import sys
from collections import deque

def solution(N,K, cnt):
    
    q = deque()
    q.append([N,cnt])
    visited[N] = 1

    while q:
        cur_index, cur_cnt = q.popleft()

        if cur_index == K:
            cnt_list.append(cur_cnt)

        for dcur in dx:
            if dcur == 2:
                nxt_index = cur_index * dcur
            else:
                nxt_index = cur_index + dcur

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
