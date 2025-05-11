#include <iostream>
using namespace std;

int T, N; // 테케 수
int dp[41][2]; // 0열: 0 출력 수, 1열: 1 출력 수 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	// N = 0, 1 초기화 
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2;i <= 40;i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	for (int i = 0;i < T;i++) {
		cin >> N;
		cout << dp[N][0] << " " << dp[N][1] << "\n";
	}

	return 0;
}