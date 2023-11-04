T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    # ///////////////////////////////////////////////////////////////////////////////////
    price_count = int(input())
    prices = list(map(int, input().split()))
    
    max_price = 0
    res = 0
    for i in range(price_count-1, -1, -1):
        if prices[i] > max_price:
            max_price = prices[i]
        else:
            res += (max_price - prices[i])
            
    print("#{} {}".format(test_case, res))
    # ///////////////////////////////////////////////////////////////////////////////////
