#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_SUM = 100000;
bool dp[MAX_SUM + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int tc = 0; tc < 3; tc++) {
        int N;
        cin >> N;

        int sum = 0;
        vector<pair<int, int>> coins(N);

        for (int i = 0; i < N; i++) {
            int coin, cnt;
            cin >> coin >> cnt;
            coins[i] = make_pair(coin, cnt);
            sum += coin * cnt;
        }

        if (sum % 2 != 0) {
            cout << "0\n";
            continue;
        }

        memset(dp, false, sizeof(dp));
        dp[sum] = true;

        for (auto info : coins) {
            int coin = info.first;
            int cnt = info.second;

            for (int i = 0; i <= sum; i++) {
                if (dp[i]) { // 가능한 값이면 
                    for (int j = 1; j <= cnt; j++) { // 현재 동전의 개수만큼 
                        if (i - j * coin >= 0) {
                            dp[i - j * coin] = true;
                        }
                    }
                }
            }
        }

        cout << (dp[sum / 2] ? "1\n" : "0\n");
    }

    return 0;
}
