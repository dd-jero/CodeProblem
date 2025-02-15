#include <iostream>
using namespace std;

int n, res = 0;
int arr[100001], dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	res = arr[0];

	for (int i = 1;i < n;i++) {
		if (arr[i] < 0) {
			if (dp[i - 1] + arr[i] > 0) {
				dp[i] = dp[i - 1] + arr[i];
			}
			else {
				dp[i] = arr[i];
			}
		}
		else {
			if (dp[i - 1] < 0) {
				dp[i] = arr[i];
			}
			else {
				dp[i] = dp[i - 1] + arr[i];
			}
		}
	}

	for (int i = 1;i < n;i++) {
		//cout << dp[i] << " ";
		res = res < dp[i] ? dp[i] : res;
	}
	
	cout << res << "\n";
}