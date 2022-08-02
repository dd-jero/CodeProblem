n = int(input())
list_tp = [list(map(int,input().split())) for _ in range(n)]                # n 번 T,P를 입력 
dp = [0 for _ in range(n+1)]

for i in range(n):
    for j in range(i + list_tp[i][0], n+1):                                 # for문의 범위에서 상담 기간을 활용
        if dp[j] < dp[i] + list_tp[i][1]:                                   # 예를 들어 상담 기간이 3일이면 3일 이후 모든 날에 금액을 더해 주는 방식으로 누적 합이 제일 큰 경우를 구할 수 있음
            dp[j] = dp[i] + list_tp[i][1]

print(dp[-1])        
