#include <iostream>
#include <string>
using namespace std;

bool isWinning(char arr[3][3], char player);
bool isValid(string str);

int main() {
    string str;
    while (true) {
        cin >> str;
        if (str == "end") break;

        if (isValid(str)) cout << "valid" << "\n";
        else cout << "invalid" << "\n";
    }
    return 0;
}

bool isWinning(char arr[3][3], char player) {
    // 가로, 세로 
    for (int i = 0; i < 3; i++) {
        if ((arr[i][0] == player && arr[i][1] == player && arr[i][2] == player) ||
            (arr[0][i] == player && arr[1][i] == player && arr[2][i] == player)) {
            return true;
        }
    }
    // 대각선 
    if ((arr[0][0] == player && arr[1][1] == player && arr[2][2] == player) ||
        (arr[0][2] == player && arr[1][1] == player && arr[2][0] == player)) {
        return true;
    }
    return false;
}

bool isValid(string str) {
    char board[3][3];
    int cnt_X = 0, cnt_O = 0, cnt_spot = 0;

    for (int i = 0; i < 9; i++) {
        board[i / 3][i % 3] = str[i];
        if (str[i] == 'X') cnt_X++;
        else if (str[i] == 'O') cnt_O++;
        else cnt_spot++;
    }

    // O,X 개수 확인 
    if (cnt_X != cnt_O && cnt_X != cnt_O + 1) return false;

    // O,X 별 승리 여부 확인 
    bool xWins = isWinning(board, 'X');
    bool oWins = isWinning(board, 'O');

    if (xWins && oWins) return false; // 둘 다 이기는 경우는 없음 
    if (xWins && cnt_X != cnt_O + 1) return false; // X가 이긴 경우에는 X의 개수가 1개 더 많아야함. 
    if (oWins && cnt_X != cnt_O) return false; // 0이 이긴 경우에는 개수 동일해야함. 
    if (!xWins && !oWins && cnt_spot != 0) return false; // 아무도 이기지 않았는데 .가 존재하면 안됨. 

    // 위 경우를 모두 통과하면 가능 
    return true;
}
