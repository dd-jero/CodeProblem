#include <iostream>
#include <vector>
using namespace std;

int T, N, M; // 테케 수, 동전 가지수, 만들어야 할 금액 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	for (int t = 0;t < T;t++) {

		// 배열 0으로 초기화
		int coins[21] = { 0, }; 
		int dp[10001] = { 0, };

		cin >> N;

		for (int i = 0;i < N;i++) {
			cin >> coins[i];
		}

		cin >> M;

		dp[0] = 1;

		for (int c = 0;c < N;c++) {
			for (int i = coins[c];i <= M;i++) {
				dp[i] += dp[i - coins[c]];
			}
		}

		cout << dp[M] << "\n";

	}

	return 0;	
}