import sys

def find_num():

    count = 1
    prev = infor[0][1]

    for j in range(1, len(infor)):
        
        if prev <= infor[j][0]:
            prev = infor[j][1]
            count += 1

    return count

n = int(sys.stdin.readline())
cnt = []
infor = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
infor.sort(key = lambda x: (x[1],x[0]))

print(find_num())
