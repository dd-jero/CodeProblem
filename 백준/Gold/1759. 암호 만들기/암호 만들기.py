from itertools import combinations                          # 조합을 이용

def make_pw():
    global collection

    for c in list(combinations(list_c, L)):                 # L개의 원소를 가지는 조합 구성 
        count_vowel = 0
        for i in collection:                                # 모음 리스트 이용
            if i in c:                                      
                count_vowel += 1                            # 모음이 존재하면 카운트 
            
        if count_vowel > 0 and (L-count_vowel) >= 2:        # 모음 개수를 제외한 요소의 개수가 2 이상일 때 
            res.append("".join(c))                          # 띄어쓰기 없이 리스트에 추가


L,C = map(int,input().split())
collection = ['a','e','i','o','u']

list_c = list(map(str,input().rstrip().split()))
list_c.sort()

res = []
make_pw()

for i in res:
    print(i)

