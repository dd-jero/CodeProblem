import sys
from itertools import permutations

n,m = map(int, sys.stdin.readline().split())

list_n = sorted(list(map(int, sys.stdin.readline().split())))

for p in permutations(list_n, m):                               # permutations 함수와 for문을 이용하여 순열 생성
    print(*p)                                                   # *를 붙여주는 이유는 permutations 함수로 생성되는 결과가 tuple이기 때문에 문제가 원하는 방식으로 출력 하기 위함
