import sys
N = int(sys.stdin.readline()) # 원하는 채널
M = int(sys.stdin.readline()) # 고장난 버튼의 개수
NOT = list(map(int, sys.stdin.readline().split())) # 고장난 버튼의 배열

min_num = abs(100 - N) # + 나 - 버튼만 이용했을 누르는 횟수를 초기 값으로 설정 

for i in range(0, 1000000+1): # 위에서 부터 내려오는 것이 더 적게 누를 수 있는 경우 존재
    i = str(i)

    for j in range(len(i)): # 해당 숫자의 길이 만큼
        if int(i[j]) in NOT: # 해당 숫자에 고장난 버튼의 숫자가 있다면
            break # 루프문 종료 

        elif j == len(i) -1: # 해당 숫자의 마지막 자리수에 도달하면
            # 초기의 + 또는 -만 이용한 횟수와 (해당 숫자 - 원하는 채널) 절댓값 + 해당 숫자 길이 비교
            min_num = min(min_num, abs(int(i) - N) + len(i)) #  최소 누르는 횟수 업데이트

print(min_num)
