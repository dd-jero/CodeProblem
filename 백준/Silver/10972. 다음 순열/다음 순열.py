n = int(input())
num = list(map(int, input().split()))

for i in range(n-1,0,-1):

    if num[i-1] < num[i]:

        for j in range(n-1,0,-1):

            if num[i-1] < num[j]:

                num[i-1], num[j] = num[j], num[i-1]
                num = num[:i] + sorted(num[i:])

                print(*num)

                exit(0)

print(-1)

