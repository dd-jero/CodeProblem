import sys

n,m = map(int,sys.stdin.readline().split())
book_dic = {}
book_list = [0,]
res= []

for i in range(1,n+1):
    name = str(sys.stdin.readline().strip())

    book_dic[name] = str(i)
    book_list.append(name)

for _ in range(m):
    temp = str(sys.stdin.readline().strip())

    if temp.isdigit():
        res.append(book_list[int(temp)])
    else:
        res.append(book_dic[temp])

for i in res:
    print(i)