#include <iostream>
#include <vector>
using namespace std;

int dp[10001];
vector<int> cost;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k; // n가지의 동전, 가치의 합 k원
	cin >> n >> k;

	cost.resize(n);

	for (int i = 0;i < n;i++) {
		cin >> cost[i];
	}

	dp[0] = 1; // 처음에 0가지로 0을 만드는 것은 1개 (아무 것도 없음)

	for (int i = 0;i < n;i++) {
		for (int j = cost[i];j <= k;j++) {
			dp[j] = dp[j] + dp[j - cost[i]];
		}
	}

	cout << dp[k];

	return 0;
}