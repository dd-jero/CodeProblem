import sys
import heapq
n = int(sys.stdin.readline())
li = []

while(1):
    if n == 0:
        break

    x = int(sys.stdin.readline())

    if x != 0:
        heapq.heappush(li,x)

    else:
        if len(li) != 0:
            num = heapq.heappop(li)
            print(num)
        else:
            print(0)

    n-=1
