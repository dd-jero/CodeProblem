import sys
import bisect

def solution(numbers):
    dp = []
    temp = []
    res = []
    
    for i in numbers:
        if not dp or dp[-1] < i:
            dp.append(i)
            temp.append((len(dp)-1,i))
        
        else:
            index = bisect.bisect_left(dp,i) # i 값의 왼쪽에서 들어갈 인덱스 
            dp[index] = i
            temp.append((index, i)) # 동일한 i면 동일한 index를 가짐
                
    last_index = len(dp)-1 # 여러 가지의 dp가 존재할 수 있어도 길이는 동일 
    
    for i in range(len(temp)-1,-1,-1): 
        if temp[i][0] == last_index:
            res.append(temp[i][1])
            last_index -= 1
    
    return res

n = int(sys.stdin.readline())
numbers = list(map(int,sys.stdin.readline().strip().split()))
res = solution(numbers)
print(len(res))
print(*reversed(res))
