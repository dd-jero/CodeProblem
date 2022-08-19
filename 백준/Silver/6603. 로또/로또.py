import sys
from itertools import combinations

while(1):
    li = list(map(int, sys.stdin.readline().rstrip().split()))

    if li[0] == 0:                                                  # 입력의 제일 첫 정수가 0이면 종료
        break

    li.pop(0)                                                       # 제일 첫 정수 제거 

    for j in list(combinations(li, 6)):                             # 제거된 리스트를 이용해서 조합
        print(*j, end= "\n")                                        # 각 테스트 케이스 사이에 한 줄 씩 띄우기 위함
        
    sys.stdout.write("\n")                                          # print 함수는 뒤에 개행 문자가 포함, sys.stdout,write 함수는 뒤에 개행 문자가 미 포함하여 출력 

