n = int(input())
all_paper = []
for _ in range(n):
    all_paper.append(list(map(int, input().split())))

white_count = 0
blue_count = 0

def divide(num, paper):
    global white_count
    global blue_count 
    check = 0

    for i in range(num):
        check += sum(paper[i])

    if check == 0:
        white_count += 1
    elif check == num*num:
        blue_count += 1
    else:
        div_paper = [paper[i][0:num//2] for i in range(0,num//2)]
        divide(num//2, div_paper)
        div_paper = [paper[i][0:num//2] for i in range(num//2,num)]
        divide(num//2, div_paper)
        div_paper = [paper[i][num//2:num] for i in range(0, num//2)]
        divide(num//2, div_paper)
        div_paper = [paper[i][num//2:num] for i in range(num//2, num)]
        divide(num//2, div_paper)

divide(n,all_paper)

print(white_count)
print(blue_count)
