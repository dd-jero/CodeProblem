#include <iostream>
#include <vector>
#include <string>
using namespace std;

string a, b;
vector<vector<int>> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b;
	int a_size = a.size();
	int b_size = b.size();
	dp.resize(a_size + 1, vector<int>(b_size + 1)); // 행: 첫 문자열의 길이 + 1, 열: 두 번째 문자열의 길이 + 1

	a = '0' + a;
	b = '0' + b;

	for (int i = 1;i <= a_size;i++) {
		for (int j = 1;j <= b_size;j++) {
			
			if (a[i] == b[j]) { // 두 문자가 같으면
				dp[i][j] = dp[i - 1][j - 1] + 1; // 이전 최대 길이 + 1
			}
			else { // 두 문자가 다르면
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 이전의 최대 길이를 저장
			}
		}
	}

	cout << dp[a_size][b_size] << "\n";

	return 0;
}