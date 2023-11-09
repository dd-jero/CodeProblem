for test_case in range(1, 10 + 1):
    # ///////////////////////////////////////////////////////////////////////////////////
    n = int(input())
    buildings = list(map(int, input().split()))
    res = 0
    
    for i in range(2, n-2):
        max_n = max(buildings[i-2],buildings[i-1],buildings[i+1], buildings[i+2])
        
        if buildings[i] < max_n:
            continue            
        else:          
            res += (buildings[i] - max_n)
    print("#{} {}".format(test_case, res)) 