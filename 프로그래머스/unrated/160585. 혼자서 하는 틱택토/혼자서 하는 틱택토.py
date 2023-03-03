def check(player,board):
    
    for i in range(3):
        if all(j == player for j in board[i]):
            return True
        
    for i in range(3):
        if all(board[j][i] == player for j in range(3)):
            return True
        
    if all(board[i][i] == player for i in range(3)):
        return True
    
    if all(board[i][2-i] == player for i in range(3)):
        return True

    return False
        
def solution(board):
    cnt_o = sum(row.count('O') for row in board)
    cnt_x = sum(row.count('X') for row in board)
    
    if (cnt_x - cnt_o > 0) or (abs(cnt_x - cnt_o) > 1):
        return 0
    elif (check('O',board) and (cnt_o - cnt_x != 1)) or (check('X',board) and (cnt_o != cnt_x)):
        return 0
    
    return 1
                  
    