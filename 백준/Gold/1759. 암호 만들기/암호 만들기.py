from itertools import combinations

def make_pw():
    global collection

    for c in list(combinations(list_c, L)):
        count_vowel = 0
        for i in collection:
            if i in c:
                count_vowel += 1
            
        if count_vowel > 0 and (L-count_vowel) >= 2:
            res.append("".join(c))


L,C = map(int,input().split())
collection = ['a','e','i','o','u']

list_c = list(map(str,input().rstrip().split()))
list_c.sort()

res = []
make_pw()

for i in res:
    print(i)

