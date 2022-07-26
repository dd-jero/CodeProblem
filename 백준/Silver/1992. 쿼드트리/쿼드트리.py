def divide(num, vid):                                                   # 분할정복과 재귀를 위한 함수 선언
    global ans                                                          # 전역 변수
    check = 0

    for i in range(num):
        for j in vid[i]:
            check += sum(map(int,j))                                    # str형을 int형으로 변환하여 합 구하기

    if check == 0:                                                      # 모두 0이면 0
        ans.append(0)


    elif check == num*num:                                              # 모두 1이면 1
        ans.append(1)

    else:                                                               # 모두 0 또는 1이 아닐 때 분할 정복
        ans.append("(")
        div_video = [vid[i][0:num//2] for i in range(0,num//2)]         # 왼쪽 상단
        divide(num//2, div_video)
        div_video = [vid[i][num//2:num] for i in range(0,num//2)]       # 오른쪽 장단
        divide(num//2, div_video)
        div_video = [vid[i][0:num//2] for i in range(num//2,num)]       # 왼쪽 하단
        divide(num//2, div_video)
        div_video = [vid[i][num//2:num] for i in range(num//2,num)]     # 오른쪽 하단
        divide(num//2, div_video)
        ans.append(")")

n = int(input())
video = []
use = []
ans = []

for _ in range(n):
    video.append(input())                                               # str형으로 영상 입력

for i in video:
    use.append(list(map(str, i)))                                       # map함수를 이용하여 각 행을 str형으로 하나씩 분리 (바로 int형으로 분리하면 0이 사라지게 됨)

divide(n,use)

for i in ans:
    print(i,end="")                                                     # 한 줄에 연속된 출력을 위한 end 키워드 
