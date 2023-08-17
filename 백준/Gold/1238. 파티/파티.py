import sys
import heapq
INF = sys.maxsize

def dijkstra(start, infor):
    dist = [INF] * (N + 1)
    
    dist[start] = 0
    hq = []
    heapq.heappush(hq,[start,dist[start]])

    while hq:
        cur_dest, cur_dist = heapq.heappop(hq)
        if dist[cur_dest] < cur_dist:
            continue

        for new_dest, new_dist in infor[cur_dest]:
            distance = cur_dist + new_dist
            if distance < dist[new_dest]:
                dist[new_dest] = distance
                heapq.heappush(hq,[new_dest,distance])

    return dist

N,M,X = map(int,sys.stdin.readline().strip().split())
times = [[] for _ in range(N + 1)]
times_reverse = [[] for _ in range(N + 1)]

for _ in range(M):
    start, end, time = map(int,sys.stdin.readline().strip().split())
    times[start].append((end,time))
    times_reverse[end].append((start,time))

go = dijkstra(X,times)
back = dijkstra(X,times_reverse)

print(max(go[i]+back[i] for i in range(1,N+1) if i != X))



