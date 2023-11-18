T = int(input())

for tc in range(1, T+1):
    N = int(input())
    scores = list(map(int, input().split()))

    visited = [True] + [False]*sum(scores) # 점수의 합 == 인덱스 (최대 합이 마지막 인덱스)
    res = [0]

    for s in scores:
        for i in range(len(res)):
            if not visited[s + res[i]]:
                visited[s+res[i]] = True
                res.append(s+res[i])
                
    print(f"#{tc} {len(res)}")