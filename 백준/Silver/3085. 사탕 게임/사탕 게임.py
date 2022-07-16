num = int(input())
board = []
result = 0

def check(list): #  해당 사탕이 연속인지 확인 
    n = len(list)
    r = 1

    for i in range(0,n):
        cnt = 1
        for j in range(0,n-1):

            if list[i][j] == list[i][j+1]:
                cnt += 1
            else:
                cnt = 1

            if cnt > r:
                r = cnt

    for i in range(0,n): # 열
        cnt = 1
        for j in range(0,n-1): # 행

            if list[j][i] == list[j+1][i]:
                cnt += 1
                
            else:
                cnt = 1

            if cnt > r:
                r = cnt        

    return r    


for i in range(num):
    row_candy = input()
    board.append(list(row_candy))

for i in range(0, num):
    temp = 0
    for j in range(0, num-1):
        board[i][j],board[i][j+1] = board[i][j+1],board[i][j]
        
        temp = check(board)

        if temp > result:
            result = temp
        
        board[i][j], board[i][j+1] = board[i][j+1],board[i][j]

for i in range(0, num):
    temp = 0
    for j in range(0, num-1):
        board[j][i],board[j+1][i] = board[j+1][i],board[j][i]
        
        temp = check(board)

        if temp > result:
            result = temp
        
        board[j][i],board[j+1][i] = board[j+1][i],board[j][i]

print(result)