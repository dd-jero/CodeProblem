import sys

n = int(sys.stdin.readline())
stack = []

for i in range(n):
    func = list(map(str, sys.stdin.readline().rstrip().split()))
    
    if func[0] == "push" :                                          # appendleft 구현 (unpacking을 하지 않으면 이중 리스트로 생성됨)
        stack.append(func[1])                                       
        stack = [stack[-1],*stack[:-1]]                             # 제일 왼쪽으로 요소를 추가하는 리스트 형성

    elif func[0] == "pop" :                                         # popleft 구현
        if len(stack) == 0:
            print(-1)
        else: 
            print(stack.pop(0))                                     # 제일 왼쪽의 요소 추출 후 출력

    elif func[0] == "top":                                          # top 구현
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[0])                                         # 제일 왼쪽(제일 위)의 요소 출력
    
    elif func[0] == "size":                                         # size 구현
        print(len(stack))                                           # 리스트의 길이 출력

    elif func[0] == "empty":                                        # empty 구현
        if len(stack) == 0:
            print(1)
        else:
            print(0)
