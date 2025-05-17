#include <iostream>
using namespace std;

int N, numbers[100001], res = -1000; // 정수 N개
int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> numbers[i];
	}

	dp[0] = numbers[0];
	for (int i = 1;i < N;i++) {
		
		if (numbers[i] >= 0) { // 현재 요소가 양수면
			if (dp[i - 1] < 0) dp[i] = numbers[i]; // 이전 최대 합이 음수면 초기화
			else dp[i] = dp[i - 1] + numbers[i]; // 합에 더하기
		}
		else { // 현재 요소가 음수면 
			int check = dp[i - 1] + numbers[i];
			if (check >= 0) dp[i] = check; // 이후 양수를 더해서 더 큰 값이 나올 수 있음.
			else dp[i] = numbers[i];
		}
	}

	for (int i = 0;i < N;i++) {
		res = res < dp[i] ? dp[i] : res;
	}

	cout << res << "\n";

	return 0;
}