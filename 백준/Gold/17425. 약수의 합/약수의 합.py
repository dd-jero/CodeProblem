dp = [1] * 1000001                  # 약수의 합 리스트
res = [0] * 1000001                 # 누적 합 리스트

for i in range(2, 1000001): 

    j = 1

    while(i*j <= 1000000):          # i*j는 약수의 곱이기 때문에 이는 문제에서 자연수의 최대 가능 숫자
        dp[i*j] += i                # index를 약수의 합을 구하고자 하는 자연수로 사용, element에 약수를 더함
        j+=1

for i in range(1, 1000001):         # 누적 합을 구하기 위한 loop문 : g(x) 구하기
    res[i] = res[i-1] + dp[i]       # (x-1)의 누적 약수의 합과 x의 약수의 합을 더함

T = int(input())
answer = []
for i in range(T):
    N = int(input())
    answer.append(res[N])

for element in answer:
    print(element)
