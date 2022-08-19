import sys

n = int(sys.stdin.readline())
bit = 0

for _ in range(n):
    func = sys.stdin.readline().split()
    
    if func[0] == "all":
        bit = (1 << 20) -1
    elif func[0] == "empty":
        bit = 0
    
    else:
        num = int(func[1]) - 1

        if func[0] == "add":
            bit |= (1 << num)

        elif func[0] == "remove":
            bit &= ~(1 << num)


        elif func[0] == "check":
            if bit & (1 << num) == 0:
                print(0)
            else:
                print(1)

        elif func[0] == "toggle":
            bit ^= (1 << num)    