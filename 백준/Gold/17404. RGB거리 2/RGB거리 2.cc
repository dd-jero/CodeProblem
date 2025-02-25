#define INF 2e9
#include <iostream>
using namespace std;

int N, res = INF;
int color[1001][3]; // 행: i번 집, 열: 빨,초,파 비용

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1;i <= N;i++) {
		cin >> color[i][0] >> color[i][1] >> color[i][2];
	}

	for (int start = 0;start <= 2;start++) { // start는 1번째 집이 선택한 색 의미 
		int dp[1001][3];

		for (int i = 0;i <= 2;i++) {
			if (i == start) dp[1][start] = color[1][start]; // 1번째 집에서 선택한 색 
			else dp[1][i] = INF; // 선택하지 않은 색은 무한대로 
		}

		// 2번째 집부터 N번째 집까지 누적 최소 비용 고려
		for (int i = 2;i <= N;i++) {
			// i 번째 집에서는 i-1번째에서 선택하지 않은 색 중 고려해야함.
			dp[i][0] = color[i][0] + min(dp[i - 1][1], dp[i - 1][2]); 
			dp[i][1] = color[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = color[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}

		for (int i = 0;i <= 2;i++) {
			if (i == start) continue; // 1번째와 N번째 집의 색은 달라야함. 
			else res = res > dp[N][i] ? dp[N][i] : res;
		}
	}

	cout << res << "\n";

	return 0;

}