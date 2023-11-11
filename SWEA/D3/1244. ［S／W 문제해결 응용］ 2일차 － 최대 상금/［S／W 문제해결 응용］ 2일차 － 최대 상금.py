# DFS와 backtracking 이용

def dfs(cnt):
    global ans
    global num_li
   
    if cnt == max_cnt:
        ans = max(ans, int("".join(num_li)))
        return
        
    for cur in range(L-1):
        for nxt in range(cur+1, L):
            num_li[cur], num_li[nxt] = num_li[nxt], num_li[cur]
            
            check = int("".join(num_li))*10+cnt # n,check로 하지 않고 하나의 정수로 cnt를 묶음 ==> 소요 시간 감소
            
            if check not in visited: # 해당 cnt에 num를 만들지 않았으면 
                dfs(cnt+1)
                visited.append(check)
            num_li[cur], num_li[nxt] = num_li[nxt], num_li[cur]

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    # ///////////////////////////////////////////////////////////////////////////////////
    num, max_cnt = input().split()
    max_cnt = int(max_cnt)
    num_li = list(num)
    L = len(num_li)
    visited  = []
    ans = 0
    dfs(0)
    
    print(f"#{test_case} {ans}")
    # ///////////////////////////////////////////////////////////////////////////////////
