#include <iostream>
using namespace std;

int N, res = 0;
int arr[1001], dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	// dp[i]: i번 인덱스 까지의 가장 큰 부분 수열의 합을 저장 
	for (int i = 0;i < N;i++) {
		dp[i] = arr[i]; // 먼저 현재 위치의 값을 저장 

		for (int j = 0;j < i;j++) {
			if (arr[j] < arr[i] && (dp[i] < dp[j] + arr[i])) {
				dp[i] = dp[j] + arr[i];
			}
		}
		res = res < dp[i] ? dp[i] : res; 
	}

	cout << res << "\n";

	return 0;
}