#include <iostream>
using namespace std;

int N; 
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3;i <= 1000;i++) {
		dp[i] = ((dp[i - 1] % 10007) + (dp[i - 2] * 2 % 10007)) % 10007;
	}

	cout << dp[N] << "\n";

	return 0;
}