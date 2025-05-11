#include <iostream>
using namespace std;

int N; // 삼각형 크기 
int triangle[501][501], dp[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	// 삼각형 수 입력 
	for (int i = 0;i < N;i++) {
		for (int j = 0;j <= i;j++) {
			cin >> triangle[i][j];
		}
	}

	// 제일 상단 초기화 
	dp[0][0] = triangle[0][0];

	for (int i = 1;i < N;i++) {
		for (int j = 0;j <= i;j++) {
			if (j == 0) dp[i][j] = dp[i - 1][0] + triangle[i][0];
			else if (j == i) {
				dp[i][j] = dp[i - 1][i - 1] + triangle[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}
	}

	int res = 0;
	for (int i = 0;i < N;i++) {
		res = res < dp[N - 1][i] ? dp[N - 1][i] : res;
	}

	cout << res << "\n";

	return 0;
}