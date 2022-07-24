def divide(num, vid):
    global ans
    check = 0

    for i in range(num):
        for j in vid[i]:
            check += sum(map(int,j))

    if check == 0:
        ans.append(0)


    elif check == num*num:
        ans.append(1)

    else:
        ans.append("(")
        div_video = [vid[i][0:num//2] for i in range(0,num//2)]
        divide(num//2, div_video)
        div_video = [vid[i][num//2:num] for i in range(0,num//2)]
        divide(num//2, div_video)
        div_video = [vid[i][0:num//2] for i in range(num//2,num)]
        divide(num//2, div_video)
        div_video = [vid[i][num//2:num] for i in range(num//2,num)]
        divide(num//2, div_video)
        ans.append(")")

n = int(input())
video = []
use = []
ans = []

for _ in range(n):
    video.append(input())

for i in video:
    use.append(list(map(str, i)))

divide(n,use)

for i in ans:
    print(i,end="")
