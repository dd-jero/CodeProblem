import sys
import itertools

n,m = sys.stdin.readline().split()
n = int(n)
m = int(m)

list_n = [str(i) for i in range(1,n+1)]
res = (list(map(' '.join,itertools.combinations(list_n, m)))) # N과 M (1) 과의 유일한 차이점 : combinations 함수를 사용
                                                              # combinations 함수는 정렬된 순서를 가지며, 반복되는 요소가 없움
for i in res:
    print(i)
