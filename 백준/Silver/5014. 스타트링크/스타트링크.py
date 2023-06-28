from collections import deque

def mincount(f, s, g, u, d):
    visited = [0 for _ in range(f+1)]
    deq = deque()

    deq.append([s,0])
    visited[s] = 1

    while deq:
        floor, count = deq.popleft()

        if floor == g:
            return count
        
        temp_f = [floor + u, floor - d]

        for tf in temp_f:
            if 1 <= tf <= f and not visited[tf]:
                deq.append([tf, count+1])
                visited[tf] = 1

    return "use the stairs"

F, S, G, U, D = map(int, input().split())
print(mincount(F,S,G,U,D))
