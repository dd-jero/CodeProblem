#define MAX 1500001
#include <iostream>

using namespace std;

int N;
int T[MAX], P[MAX];
int dp[MAX]; // 상담 걸리는 기간, 받을 수 있는 금액 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1;i <= N;i++) {
		cin >> T[i] >> P[i];
	} // 입력 완료 

	// dp[i]: i일 전까지 번 최대 액수 => 그래서 N+1까지 해야 마지막날까지 번 최대 액수를 계산 가능 
	int max_val = 0; // 현재까지 얻은 최대 액수
	for (int i = 1;i <= N+1;i++) {
		max_val = dp[i] > max_val ? dp[i] : max_val; 
		
		if (i + T[i] > N+1) continue; // 퇴사일을 넘어가면 

		// 현재 상담의 보수 + 이전까지 최대 이익 vs 기존 이익 값 
		dp[i + T[i]] = max(P[i] + max_val, dp[i + T[i]]); 
	}

	cout << max_val << "\n";

	return 0;
}