# itertools 라이브러리를 이용하면 초과 발생
# 입력 받은 수를 그대로 이용해서 위치를 바꾸는 형식으로 코드 구현

n = int(input())
num = list(map(int, input().split()))

for i in range(n-1,0,-1):                                   # 리스트 맨 뒤부터 확인 

    if num[i-1] < num[i]:                                   # 현재 index의 요소가 앞 index의 요소보다 클 경우
                                                            # 예를 들어 2 3 1의 다음 순열을 찾고자 한다면, 3 > 1 이기 때문에 if문 만족X, 첫 for문 계속
        for j in range(n-1,0,-1):                           # 2 < 3 이기 때문에 if문 만족 (현재 i는 1) => 새로운 for문을 이용하여 2보다 큰 요소 확인
                                                            # 두 요소를 스왑하고 index i 이전까지의 리스트와 오름차순으로 정렬된 i 이후의 리스트를 num으로 업데이트 
            if num[i-1] < num[j]:  

                num[i-1], num[j] = num[j], num[i-1]
                num = num[:i] + sorted(num[i:])

                print(*num)                                 # 리스트의 요소들을 출력

                exit(0)                                     # 강제 종료

print(-1)                                                   # for문이 끝까지 다 돌았으면 -1 출력

