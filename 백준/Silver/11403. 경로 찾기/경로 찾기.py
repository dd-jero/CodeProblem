import sys
import copy

def solution(route):
    res = copy.deepcopy(route)

    for mid in range(n):
        for start in range(n):
            for end in range(n):
               
                if res[start][mid] and res[mid][end]:
                    res[start][end] =1 

    return res

n = int(sys.stdin.readline())
route = []


for _ in range(n):
    route.append(list(map(int,sys.stdin.readline().split())))

ans = solution(route)

for i in range(n):
    print(*ans[i])
