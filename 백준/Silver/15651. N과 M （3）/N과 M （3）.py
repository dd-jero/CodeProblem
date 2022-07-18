import sys
import itertools

n,m = sys.stdin.readline().split()
n = int(n)
m = int(m)

list_n = [str(i) for i in range(1,n+1)]
res = (list(map(' '.join,itertools.product(list_n, repeat = m)))) # product 함수와 repeat 키워드를 이용하여 중복 순열 생성 
                                                                  # 데카르트 곱 ( 곱집합 )
for i in res:
    print(i)
