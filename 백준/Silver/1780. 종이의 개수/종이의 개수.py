import sys

def find(paper, num):
    global res
    temp_paper = []

    for i in paper:
        temp_paper.extend([*i])

    temp_paper = set(temp_paper)

    if len(temp_paper) == 1:

        if -1 in temp_paper:
            res[0] += 1
            return
        elif 0 in temp_paper:
            res[1] += 1
            return
        elif 1 in temp_paper:
            res[2] += 1
            return

    else:
        div_paper = [paper[i][0:num//3] for i in range(0, num//3)]
        find(div_paper, num//3)
        div_paper = [paper[i][0:num//3] for i in range(num//3, 2*(num//3))]
        find(div_paper, num//3)
        div_paper = [paper[i][0:num//3] for i in range(2*(num//3), num)]
        find(div_paper, num//3)
        div_paper = [paper[i][num//3:2*(num//3)] for i in range(0, num//3)]
        find(div_paper, num//3)
        div_paper = [paper[i][num//3:2*(num//3)] for i in range(num//3,2*(num//3))]
        find(div_paper, num//3)
        div_paper = [paper[i][num//3:2*(num//3)] for i in range(2*(num//3), num)]
        find(div_paper, num//3)
        div_paper = [paper[i][2*(num//3):num] for i in range(0, num//3)]
        find(div_paper, num//3)
        div_paper = [paper[i][2*(num//3):num] for i in range(num//3,2*(num//3))]
        find(div_paper, num//3)
        div_paper = [paper[i][2*(num//3):num] for i in range(2*(num//3), num)]
        find(div_paper, num//3)
        
n = int(sys.stdin.readline())
res = [0,0,0]
matrix = []
for i in range(n):
    matrix.append(list(map(int,sys.stdin.readline().split())))

find(matrix, n)

for i in res:
    print(i)


