T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    # ///////////////////////////////////////////////////////////////////////////////////
    tc = int(input())
    num_list = list(map(int, input().split()))
    dic = {i:0 for i in range(0,100+1)}

    for num in num_list:
        dic[num] += 1
    max_list = [k for k,v in dic.items() if max(dic.values()) == v]
    print(f"#{tc} {max(max_list)}")
    # ///////////////////////////////////////////////////////////////////////////////////
