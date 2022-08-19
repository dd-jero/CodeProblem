import sys
from itertools import combinations

while(1):
    li = list(map(int, sys.stdin.readline().rstrip().split()))

    if li[0] == 0:
        break

    li.pop(0)

    for j in list(combinations(li, 6)):
        print(*j, end= "\n")
        
    sys.stdout.write("\n")

