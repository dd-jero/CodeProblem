#include <iostream>
using namespace std;

int N, M;
int arr[2001];
int dp[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}
	
	// 길이가 1일 때
	for (int i = 1;i <= N;i++) {
		dp[i][i] = 1; // 자기 자신만은 팰린드롬 
	}

	// 길이가 2일 때
	for (int i = 1;i < N;i++) {
		if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
	}

	// 길이가 3 이상이면
	for (int i = N - 2; i >= 1; i--) {
		for (int j = i + 2; j <= N;j++) {
			if ((arr[i] == arr[j]) && dp[i + 1][j - 1] == 1) dp[i][j] = 1;
		}
	}

	cin >> M;

	int S, E;
	for (int i = 0;i < M;i++) {
		cin >> S >> E;
		cout << dp[S][E] << "\n";
	}

	return 0;
}