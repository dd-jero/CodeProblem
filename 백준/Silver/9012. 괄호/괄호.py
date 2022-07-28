import sys
from collections import deque

n = int(sys.stdin.readline())

for i in range(n):
    stack = deque()
    test_data = sys.stdin.readline().rstrip()

    for j in range(len(test_data)):

        if test_data[j] == '(':
            stack.appendleft(test_data[j])
        
        elif test_data[j] == ')':
            if len(stack) == 0:
                stack.appendleft(')')
            else:
                if stack[0] == '(':
                    stack.popleft()
                else:
                    stack.appendleft(')')
    
    if len(stack) == 0:
        print('YES')
    
    else:
        print('NO')
