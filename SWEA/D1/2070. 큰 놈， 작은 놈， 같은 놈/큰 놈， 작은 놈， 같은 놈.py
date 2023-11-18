T = int(input())

for tc in range(1,T+1):
    n1, n2 = map(int, input().split())

    if n1 > n2:
        print(f"#{tc} >")
    elif n1 < n2:
        print(f"#{tc} <")
    else:
        print(f"#{tc} =")