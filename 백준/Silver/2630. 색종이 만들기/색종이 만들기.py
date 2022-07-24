n = int(input())
all_paper = []
for _ in range(n):
    all_paper.append(list(map(int, input().split())))                   # 이중 리스트로 종이 행렬 입력

white_count = 0
blue_count = 0

def divide(num, paper):                                                 # 분할 정복과 재귀를 위한 함수 정의
    global white_count
    global blue_count 
    check = 0

    for i in range(num):                                                # 해당 종이의 요소를 모두 더하기
        check += sum(paper[i])

    if check == 0:                                                      # 더한 값이 0 이면 흰 종이
        white_count += 1
    elif check == num*num:                                              # 더한 값이 행렬의 크기와 같으면 파란 종이
        blue_count += 1
    else:                                                               # 흰/파란 종이가 아닐 때 분할 정복 및 재귀
        div_paper = [paper[i][0:num//2] for i in range(0,num//2)]       # 가로 0 ~ 절반, 세로 0 ~ 절반
        divide(num//2, div_paper)                                       # 재귀로 흰/파란 종이 확인
        div_paper = [paper[i][0:num//2] for i in range(num//2,num)]     # 가로 절반 ~ 끝, 세로 0 ~ 절반
        divide(num//2, div_paper)
        div_paper = [paper[i][num//2:num] for i in range(0, num//2)]    # 가로 0 ~ 절반, 세로 절반 ~ 끝
        divide(num//2, div_paper)
        div_paper = [paper[i][num//2:num] for i in range(num//2, num)]  # 가로 절반 ~ 끝, 세로 절반 ~ 끝
        divide(num//2, div_paper)

divide(n,all_paper)

print(white_count)
print(blue_count)
