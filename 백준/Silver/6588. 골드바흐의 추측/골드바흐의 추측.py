import sys
a = [False, False] + [True]* 999999
odd = []

for i in range(2,1000001):
    if a[i]:
        odd.append(i)
        for j in range(2*i, 1000001, i):
            a[j] = False

odd.remove(2)

while(1):
    
    count = 1

    n = int(sys.stdin.readline())

    if n != 0:
        
        for i in odd:
            
            if a[n-i]:
                print("{} = {} + {}".format(n,i, (n-i)))
                count = 0
                break
            
        if count == 1:
            print("Goldbach's conjecture is wrong.")
    
    else:
        break