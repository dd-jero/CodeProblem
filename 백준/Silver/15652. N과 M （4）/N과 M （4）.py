import sys
import itertools

n,m = sys.stdin.readline().split()
n = int(n)
m = int(m)

list_n = [str(i) for i in range(1,n+1)]
res = (list(map(' '.join,itertools.combinations_with_replacement(list_n, m)))) # combinations_with_replacement 함수를 이용하여 중복 조합 구성

for i in res:
    print(i)
   
'''
순열 : 서로 다른 N개에서 중복을 허락하지 않고 R개를 일렬로 나열하는 수 
중복 순열 : 서로 다른 N개에서 중복을 허락하고 R개를 일렬로 나열하는 수
--------순열에서 순서가 사라지면 조합이 된다!!!-------------
조합 : 서로 다른 N개에서 순서를 생각하지 않고 중복을 허락하지 않으며 R개를 선택 
중복 조합 : 서로 다른 N개에서 순서를 생각하지 않고 중복을 허락하여 R개를 선택
'''
