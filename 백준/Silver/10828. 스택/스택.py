import sys

n = int(sys.stdin.readline())
stack = []

for i in range(n):
    func = list(map(str, sys.stdin.readline().rstrip().split()))
    
    if func[0] == "push" :
        stack.append(func[1])
        stack = [stack[-1],*stack[:-1]]

    elif func[0] == "pop" :
        if len(stack) == 0:
            print(-1)
        else: 
            print(stack.pop(0))

    elif func[0] == "top":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[0])
    
    elif func[0] == "size":
        print(len(stack))

    elif func[0] == "empty":
        if len(stack) == 0:
            print(1)
        else:
            print(0)
