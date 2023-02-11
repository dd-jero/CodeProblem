from collections import deque

def solution(s):
    deq = deque()
    
    for i in s:
        deq.append(i)
        if len(deq) > 1:
            if deq[-2] == '(' and deq[-1] == ')':
                del deq[-2]
                del deq[-1]

    if deq:
        return False
    else:
        return True
    
