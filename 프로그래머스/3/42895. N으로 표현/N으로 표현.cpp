#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    vector<unordered_set<int>> DP(9); // DP[1]~DP[8]

    for (int i = 1; i <= 8; i++) {
        // 이어붙이기 숫자: N, NN, NNN 등
        int repeated = 0;
        for (int k = 0; k < i; k++) {
            repeated = repeated * 10 + N;
        }
        DP[i].insert(repeated);

        // 사칙연산 조합
        for (int j = 1; j < i; j++) {
            for (int a : DP[j]) {
                for (int b : DP[i-j]) {
                    DP[i].insert(a + b);
                    DP[i].insert(a - b);
                    DP[i].insert(a * b);
                    if (b != 0) DP[i].insert(a / b);
                }
            }
        }

        // 목표 숫자 확인
        if (DP[i].count(number)) return i;
    }
    return -1; // 8번 넘게 써도 불가능할 경우

}