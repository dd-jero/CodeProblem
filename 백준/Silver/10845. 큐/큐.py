import sys 
q = []
n = int(sys.stdin.readline())

for i in range(n):

    func = list(map(str,sys.stdin.readline().rstrip().split()))

    if func[0] == 'push':
        q.append(int(func[1]))
    
    elif func[0] == 'pop':
        if q :
            print(q.pop(0))
        
        else:
            print(-1)
    
    elif func[0] == 'size':
        print(len(q))

    elif func[0] == 'empty':
        if q :
            print(0)
        else:
            print(1)
    
    elif func[0] == 'front':
        if q :
            print(q[0])
        else:
            print(-1)

    elif func[0] == 'back':
        if q :
            print(q[-1])
        
        else:
            print(-1)