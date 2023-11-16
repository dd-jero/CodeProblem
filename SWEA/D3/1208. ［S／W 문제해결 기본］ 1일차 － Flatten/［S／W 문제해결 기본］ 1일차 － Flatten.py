T = 10
for test_case in range(1, T + 1):
    max_dump = int(input())
    boxs = list(map(int, input().split()))

    for cnt in range(max_dump):
        diff = max(boxs) - min(boxs)
        if diff == 1 or diff == 0:
            break
        else:
            boxs[boxs.index(max(boxs))] -= 1
            boxs[boxs.index(min(boxs))] += 1

        diff = max(boxs) - min(boxs) # dump하고 한번 더 차이를 구해주어야 함 (dump=1, 3,1 인 경우 고려)
        if diff == 1 or diff == 0:
            break


    print(f"#{test_case} {diff}")