from itertools import permutations

n = int(input())
res = 0

num = list(map(int,input().split()))

for i in list(permutations(num,n)):
    temp = 0

    for j in range(n-1): 
        temp += abs(i[j]-i[j+1])
    
    res = max(res, temp)

print(res)
