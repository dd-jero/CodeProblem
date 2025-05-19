#include <iostream>
#include <vector>
using namespace std;

int N, res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	vector<int> numbers(N);
	vector<int> dp(N);

	for (int i = 0;i < N;i++) {
		cin >> numbers[i];
	}
	
	dp[0] = numbers[0];


	for (int i = 1;i < N;i++) {
		dp[i] = numbers[i];

		for (int j = i - 1; j >= 0;j--) {
			if (numbers[j] < numbers[i]) {
				dp[i] = max(dp[i], dp[j] + numbers[i]);
				
			}
		}
	}

	for (int i = 0;i < N;i++) {
		res = res < dp[i] ? dp[i] : res;
	}

	cout << res << "\n";

	return 0;

}