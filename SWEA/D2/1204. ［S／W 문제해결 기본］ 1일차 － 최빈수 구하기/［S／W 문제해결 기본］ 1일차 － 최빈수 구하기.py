T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    # ///////////////////////////////////////////////////////////////////////////////////
    tc = int(input())
    num_list = list(map(int, input().split()))
    dic = {i:0 for i in range(0,100+1)} #dictionary 사용 (점수는 0 ~ 100 범위임)

    for num in num_list:
        dic[num] += 1
        
    max_list = [k for k,v in dic.items() if max(dic.values()) == v] # max의 value를 가지는 key들을 리스트에 저장 
    print(f"#{tc} {max(max_list)}")
    # ///////////////////////////////////////////////////////////////////////////////////
