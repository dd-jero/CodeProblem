#define INF -1e9
#include <iostream>
using namespace std;

int N, M;
int arr[1002][1002];
int dp[1002][1002], dp2[1002][1002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0;i <= M;i++) {
		dp[0][i] = dp2[0][i] = INF;
 	}

	for (int i = 0;i <= N;i++) {
		dp[i][0] = dp2[i][0] = INF;
		dp[i][M + 1] = dp2[i][M + 1] = INF;
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> arr[i][j];
		}
	}
	
	// dp 초기화
	dp[1][1] = dp2[1][1] = arr[1][1];

	// 1행은 무조건 왼쪽부터 채울 수 밖에 없음 (위쪽으로 이동 불가능)
	for (int i = 2; i <= M;i++) {
		dp[1][i]= dp2[1][i] = arr[1][i] + dp[1][i - 1];
	}

	// 한번 탐사한 지역은 탐사X
	for (int i = 2;i <= N;i++) {
		// 왼쪽에서 오른쪽으로
		for (int j = 1; j <= M; j++) {
			dp[i][j] = arr[i][j] + max(dp[i][j - 1], dp[i - 1][j]);
		}
		// 오른쪽에서 왼쪽으로
		for (int j = M; j >= 1; j--) {
			dp2[i][j] = arr[i][j] + max(dp2[i][j + 1], dp2[i - 1][j]);
		}
		 
		for (int j = 1; j <= M;j++) {
			dp[i][j] = max(dp[i][j], dp2[i][j]);
			dp2[i][j] = dp[i][j];
		}
	}

	cout << dp[N][M] << "\n";


	return 0;
}