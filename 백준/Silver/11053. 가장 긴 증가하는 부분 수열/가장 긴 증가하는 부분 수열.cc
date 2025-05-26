#include <iostream>
#include <vector>
using namespace std;

int N, res = 0;
vector<int> nums, dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	dp.resize(N);
	
	int num;
	for (int i = 0;i < N;i++) {
		cin >> num;
		nums.push_back(num);
	}

	dp[0] = 1;
	for (int i = 1;i < N;i++) {

		int cur_max = 1;

		for (int j = i - 1;j >= 0;j--) {
			if (nums[i] > nums[j]) { // 현재 숫자보다 작으면
				cur_max = max(cur_max, dp[j] + 1);
			}
		}

		dp[i] = cur_max;
	}

	for (int i = 0;i < N;i++) {
		res = max(res, dp[i]);
	}

	cout << res << "\n";

	return 0;
}