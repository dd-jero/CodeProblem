import sys

def cal(num):
    
    for i in range(num):
        height_list = list(map(int, input().split()))
        step = 0
        del height_list[0]
        
        for j in range(1,20):
            if  height_list[j-1] > height_list[j]:
                minIndex = j 
                temp = height_list.pop(minIndex)
                
                for k in range(minIndex):
                    if height_list[k] > temp:
                        step += (minIndex -k)
                        height_list = height_list[:k] + [temp] + height_list[k:]
                        break                        
        print(i+1, step)

num = int(sys.stdin.readline())
cal(num)
