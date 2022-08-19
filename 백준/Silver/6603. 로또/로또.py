import sys
from itertools import combinations

while(1):
    li = list(map(int, sys.stdin.readline().rstrip().split()))

    if li[0] == 0:                                                  # 입력의 제일 첫 정수가 0이면 종료
        break

    li.pop(0)                                                       # 제일 첫 정수

    for j in list(combinations(li, 6)):
        print(*j, end= "\n")
        
    sys.stdout.write("\n")

