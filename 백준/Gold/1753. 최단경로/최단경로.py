from sys import stdin
import heapq

# 다익스트라: 1대n, 시작정점에서 다른 모든 정점으로의 최단 경로를 구하는 알고리즘
def dijkstra(graph,start):
    distances = {node: float("inf") for node in graph} # float("int")는 무한대를 의미, 초기에 무한대로 초기화
    distances[start] = 0 # 시작노드의 값은 0
    q = []
    heapq.heappush(q, [distances[start],start])

    while q:
        cur_dis, cur_dest = heapq.heappop(q)

        if distances[cur_dest] < cur_dis:
            continue

        for new_dest, new_dis in graph[cur_dest].items():
            dis = cur_dis + new_dis
            if dis < distances[new_dest]:
                distances[new_dest] = dis
                heapq.heappush(q,[dis,new_dest])

    return distances          

vertx, edge = map(int, stdin.readline().split())
start = int(stdin.readline())
graph = {}

for i in range(1,vertx+1):
    graph[i] = {}

for _ in range(edge):
    u,v,w = map(int,stdin.readline().split())
    if v in graph[u]:
        temp = graph[u][v]

        if temp > w:
            graph[u][v] = w
    else:
        graph[u][v] = w
    
res = dijkstra(graph,start)

for n,w in res.items():
    if n in res:
        if w == float("inf"):
            print("INF")
        else:
            print(w)
