import sys
import bisect

def solution(numbers):
    dp = [numbers[0]] # 그냥 아무 숫자 하나로 채움

    for i in range(n):
        if numbers[i] > dp[-1]: # dp의 마지막 요소보다 현재 numbers의 값이 크면
            dp.append(numbers[i]) # dp에 삽임
        else: # 현재 numbers 값이 작을 경우
            idx = bisect.bisect_left(dp,numbers[i]) # 정렬된 dp에서 numbers[i]가 왼쪽에 들어갈 인덱스 반환 
            dp[idx]=numbers[i] # 반환된 인덱스에 현재 numbers 값 저장
    return len(dp)

n = int(sys.stdin.readline())
numbers = list(map(int,sys.stdin.readline().strip().split()))

print(solution(numbers))
