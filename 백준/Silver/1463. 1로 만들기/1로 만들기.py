import sys
n = int(sys.stdin.readline())
dp = [0]*1000001                            # 문제에서 10^6보다 작거나 같은 정수라 했으므로 0 ~ 1000000의 index 리스트 선언

for i in range(2, n+1):                     # 단순 반목문을 사용하는 Bottom-Up 방식 (Dynamic Programming)

    dp[i] = dp[i-1] + 1                     # 1을 빼는 연산(예를 들면 99, 100를 비교했을 때 100은 99보다 1을 빼는 연산이 한 번 더 필요)

    if i % 2 == 0:                          # 2로 나누어 떨어지면 2로 나눔
        dp[i] = min(dp[i], dp[i//2]+1)      # 6과 12를 예로 들면, 12는 6보다 2로 나누는 연산이 한번 더 필요
    if i % 3 == 0:                          # 3으로 나누어 떨어지면 3으로 나눔
        dp[i] = min(dp[i],dp[i//3]+1)

print(dp[n])                                # 1000000 까지의 자연수를 최소 연산 수를 모두 구한 뒤 결과 출력
