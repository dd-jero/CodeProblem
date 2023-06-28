from collections import deque

def mincount(f, s, g, u, d):
    # 해당층 방문 여부
    visited = [0 for _ in range(f+1)]     
    # queue 사용         
    deq = deque()

    # 처음 강호가 있는 층과 버튼 수를 묶어 queue에 삽입
    deq.append([s,0])
    # 처음 강호가 있는 층은 방문
    visited[s] = 1

    while deq:
        # 강호가 처음 있는 층부터 시작하게 됨.
        floor, count = deq.popleft()

        # G층에 도착하면 버튼 수 반환
        if floor == g:
            return count
        
        # u층 위, d층 아래
        temp_f = [floor + u, floor - d]

        # 해당 층이 범위 내에 존재하고 방문하지 않았으면 queue 추가 및 방문 체크 
        for tf in temp_f:
            if 1 <= tf <= f and not visited[tf]:
                deq.append([tf, count+1])
                visited[tf] = 1

    # queue가 비면 (해당 층으로 이동 불가)
    return "use the stairs"

F, S, G, U, D = map(int, input().split())
print(mincount(F,S,G,U,D))

