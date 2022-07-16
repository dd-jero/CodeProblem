dp = [1] * 1000001
res = [0] * 1000001

for i in range(2, 1000001):

    j = 1

    while(i*j <= 1000000):
        dp[i*j] += i
        j+=1

for i in range(1, 1000001):    
    res[i] = res[i-1] + dp[i]

T = int(input())
answer = []
for i in range(T):
    N = int(input())
    answer.append(res[N])

for element in answer:
    print(element)