from itertools import permutations

n = int(input())
res = 0

num = list(map(int,input().split()))

for i in list(permutations(num,n)):                     # for문과 permutations 함수를 이용
    temp = 0

    for j in range(n-1):                                # temp 변수를 이용하여 얻고자 하는 값을 계산 
        temp += abs(i[j]-i[j+1])
    
    res = max(res, temp)                                # 이전 값과 구한 값의 비교 => 모든 순열의 값을 계산하면서 가장 큰 계산 값으로 업데이트 

print(res)
