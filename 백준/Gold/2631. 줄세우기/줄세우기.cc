#include <iostream>
using namespace std;

int N, res = 0;
int children[201];
int dp[201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1;i < N+1;i++) {
		cin >> children[i];
	}

	for (int i = 1;i < N + 1;i++) {
		dp[i] = 1;

		for (int j = 1;j <= i;j++) {
			if (children[i] > children[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}

		res = dp[i] > res ? dp[i] : res;

	}

	cout << N - res << "\n";

	return 0;
}