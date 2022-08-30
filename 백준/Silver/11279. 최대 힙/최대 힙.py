import sys
import heapq
n = int(sys.stdin.readline())
li = []

while(1):
    if n == 0:
        break

    x = int(sys.stdin.readline())

    if x != 0:
        heapq.heappush(li,-x)                       # 자연수를 음수로 바꾸어 heap 추가 

    else:
        if len(li) != 0:
            num = heapq.heappop(li)*(-1)            # 최소 값을 pop하여 -를 곱하면 최대 값
            print(num)
        else:
            print(0)

    n-=1

