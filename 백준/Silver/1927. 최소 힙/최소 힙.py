import sys
import heapq
n = int(sys.stdin.readline())
li = []

while(1):
    if n == 0:
        break

    x = int(sys.stdin.readline())

    if x != 0:                                  # 0이 아니면 리스트에 요소 추가
        heapq.heappush(li,x)

    else:
        if len(li) != 0:                        # 리스트에 요소가 있으면
            num = heapq.heappop(li)             # 리스트 최소 값 추출
            print(num)
        else:                                   # 리스트에 요소가 없으면
            print(0)                            # 0 출력

    n-=1
