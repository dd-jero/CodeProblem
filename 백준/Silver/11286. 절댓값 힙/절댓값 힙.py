import sys
import heapq
n = int(sys.stdin.readline())
li = []

for _ in range(n):
    information = int(sys.stdin.readline())
    if information != 0:
        heapq.heappush(li,(abs(information),information))
    else:
        if li:
            print(heapq.heappop(li)[1])
        else:
            print(0)
