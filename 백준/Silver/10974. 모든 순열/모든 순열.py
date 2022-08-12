from itertools import permutations

n = int(input())
num = []
for i in range(1,n+1):
    num.append(i)

for i in permutations(num,n):
    print(*i)