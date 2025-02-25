#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int dp[501][501];
int dims[501];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int r, c;
        cin >> r >> c;
        dims[i - 1] = r;  // 이전 행렬의 열 수와 현재 행렬의 행 수는 동일
        if (i == N) dims[N] = c;
    }

    // c: 곱할 행렬 개수 (2개부터 시작)
    for (int c = 2; c <= N; c++) {
        for (int i = 1; i <= N - c + 1; i++) { // 시작점 i
            int j = i + c - 1; // 끝점 j
            dp[i][j] = INT_MAX;

            // 모든 분할점 k 시도 (i ≤ k < j)
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[1][N] << "\n";
    return 0;
}
