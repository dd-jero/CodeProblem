import sys
INF = float('inf')

def tsp(dists):
    N = len(dists)
    VISITED_ALL = (1 << N) - 1
    cache = [[None] * (1 << N) for _ in range(N)] # 최대 NxN번을 지나

    def find_path(last, visited):
        if visited == VISITED_ALL:
            return dists[last][0] or INF

        if cache[last][visited] is not None:
            return cache[last][visited]
            
        tmp = INF        
        for city in range(N):
            if visited & (1 << city) == 0 and dists[last][city] != 0:
                tmp = min(tmp,find_path(city, visited | (1 << city)) + dists[last][city])
        cache[last][visited] = tmp
        return tmp
                
    return find_path(0, 1 << 0)

n = int(sys.stdin.readline().strip())
dist = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
print(tsp(dist))