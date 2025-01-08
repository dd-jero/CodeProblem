#include <iostream>
#include <vector>
using namespace std;

int N, S, M, res = -1; // 곡의 개수, 시작 볼륨, 최대 볼륨
vector<int> volumes;
vector<vector<bool>> dp;

int main() {

	cin >> N >> S >> M;

	volumes.resize(N);
	dp.resize(N + 1, vector<bool>(M + 1,false));
	dp[0][S] = true;

	for (int i = 0;i < N;i++) {
		cin >> volumes[i];
	}

	for (int i = 1;i <= N;i++) { // 곡의 개수 
		for (int j = 0; j <= M;j++) { // 봄륨의 범위
			if (dp[i-1][j]) { // 이전에 만든 볼륨
				if (j + volumes[i-1] <= M) {
					dp[i][j + volumes[i-1]] = true;
				}

				if (j - volumes[i-1] >= 0) {
					dp[i][j - volumes[i-1]] = true;
				}
			}
		}
	}

	for (int i = M;i >= 0;i--) {
		if (dp[N][i]) {
			res = i;
			break;
		}
	}

	cout << res;

	return 0;
}