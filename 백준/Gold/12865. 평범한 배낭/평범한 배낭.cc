#include <iostream>
using namespace std;

int N, K; // 물품 수, 버틸 수 있는 무게
int W[101], V[101]; // 각 물품의 무게와 가치
int dp[101][100001]; // 행: 물품 인덱스, 열: 무게 dp[i][j]: i번째 물품까지 고려, j 무게 일 때 최대 가능 가치 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 1;i <= N;i++) {
		cin >> W[i] >> V[i];
	}

	for (int i = 1;i <= N;i++) { // 1번 물품 부터 
		for (int j = 0;j <= K;j++) { // 0 ~ 버틸 수 있는 무게 고려
			if (j >= W[i]) { // 현재 물품을 담을 수 있으면
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]); // 이전 물품에서의 현재 무게 상 최대 가치와 비교 
			}
			else { // 현재 물품을 담지 못하면
				dp[i][j] = dp[i - 1][j]; // 이전 물품에서의 현재 무게 상 최대 가치 저장
			}
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}