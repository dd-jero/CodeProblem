from collections import deque

def solution(n):
    answer = 0
    
    li = deque([i for i in range(1,n+1)])
    
    while(li):
        deq = deque()
        for num in li:
            deq.append(num)

            if sum(deq) == n:
                answer += 1
                break
            elif sum(deq) > n:
                break
        li.popleft()
        
    return answer
            
        
        
   