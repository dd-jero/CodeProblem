import sys                                                          # 입출력 시간 감소를 위한 라이브러리
import itertools                                                    # 효율적인 루핑을 위한 이터레이터를 만드는 라이브러리

n,m = sys.stdin.readline().split()                                  # split 함수로 n과 m을 한 줄에 입력
n = int(n)
m = int(m)

list_n = [str(i) for i in range(1,n+1)]                             # 1부터 n까지의 자연수를 가지는 리스트 선언
res = (list(map(' '.join,itertools.permutations(list_n, m))))       # permutation(A,B) : A에서 B개의 원소로 수열 만들기(모든 가능한 순서)
                                                                    # join 함수를 이용하여 띄어 쓰기 하나로 구분하여 조건을 만족하는 수열들을 요소로 만들기 
for i in res:                                                       # 이미 res 리스트에서의 요소에 join 함수로 공백을 주었기 때문에 요소들을 출력하기 만 하면 됨
    print(i)
