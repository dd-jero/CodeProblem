t = int(input())

for i in range(t):
    h,w,n = map(int,input().split())
    if n % h != 0:
        floor = n%h
        ho = n//h + 1
    else:
        floor = h
        ho = n // h

    print(floor*100 + ho)