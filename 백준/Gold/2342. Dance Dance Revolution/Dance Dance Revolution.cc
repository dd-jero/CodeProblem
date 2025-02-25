#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;
int dp[5][5][100002]; // dp[왼발위치][오른발위치][단계] = 최소 힘
int sequence[100002]; // 입력 수열 저장
int n = 0; // 총 단계 수

int GetCost(int from, int to) {
    if (from == to) return 1; // 같은 지점
    if (from == 0) return 2;  // 중앙에서 이동
    int diff = abs(from - to);
    return (diff == 2) ? 4 : 3; // 반대편(차이 2)이면 4, 인접(차이 1 or 3)이면 3
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); // 입출력 속도 향상

    // 1. 입력 처리
    int num;
    while (cin >> num && num != 0) {
        sequence[++n] = num;
    }

    // 2. DP 배열 초기화 (모든 값을 INF로 설정)
    fill(&dp[0][0][0], &dp[4][4][n + 1], INF);
    dp[0][0][0] = 0; // 시작 상태 (두 발 모두 중앙)

    for (int step = 1; step <= n; ++step) {
        int target = sequence[step]; // 현재 단계의 목표 지점

        // 이전 단계의 모든 가능한 발 상태 순회
        for (int left = 0; left < 5; left++) {
            for (int right = 0; right < 5; right++) {

                // 유효하지 않은 이전 상태 건너뜀
                if (dp[left][right][step - 1] == INF) continue;

                // Case 1: 왼발을 target으로 이동
                int new_left = target;
                int cost = GetCost(left, new_left);
                dp[new_left][right][step] = min(dp[new_left][right][step],dp[left][right][step - 1] + cost);

                // Case 2: 오른발을 target으로 이동
                int new_right = target;
                cost = GetCost(right, new_right);
                dp[left][new_right][step] = min(dp[left][new_right][step],dp[left][right][step - 1] + cost);
            }
        }
    }

    // 최종 계산 (마지막 단계의 최소값)
    int result = INF;
    for (int left = 0; left < 5; ++left)
        for (int right = 0; right < 5; ++right)
            result = min(result, dp[left][right][n]);

    cout << result;
    return 0;
}
