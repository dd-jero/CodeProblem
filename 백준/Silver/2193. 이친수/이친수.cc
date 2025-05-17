#include <iostream>
using namespace std;

int N; // N 자리 이친 수
long long dp[91]; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3;i <= N;i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N] << "\n";
	return 0;
}