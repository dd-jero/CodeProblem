import sys
                                                                                # 이중 for문을 이용하면 100,000^2 > 2이기 때문에 시간초과
def find_num():

    count = 1
    prev = infor[0][1]

    for j in range(1, len(infor)):
        
        if prev <= infor[j][0]:
            prev = infor[j][1]
            count += 1

    return count

n = int(sys.stdin.readline())
infor = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

infor.sort(key = lambda x: (x[1],x[0]))                                         # sort 함수에 key를 이용, 종료 시간을 0순위/시작 시간을 1순위로 하여 배열 정렬 => 회의 시간이 짧으면서 시작 시간이 빠른 순으로 정렬됨을 확인할 수 있음. 

print(find_num())
