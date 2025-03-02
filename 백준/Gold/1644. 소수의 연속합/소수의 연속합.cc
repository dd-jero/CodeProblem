#include <iostream>
#include <vector>
using namespace std;

int N;
vector<bool> prime;
vector<int> num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	prime.assign(N+1, true);

	// 에라토스테네스의 체 
	for (int i = 2;i * i <= N;i++) {
		for (int j = i * i; j <= N; j += i) {
			prime[j] = false; // 소수 아님
		}
	}

	// 소수인 수
	for (int i = 2;i <= N;i++) {
		if (prime[i]) num.push_back(i);
	}
	
	int num_size = num.size();
	int start = 0, end = 0, cur_sum = 0, res = 0;

	while (start <= end) {
		if (cur_sum >= N) {
			cur_sum -= num[start++];
		}
		
		if (cur_sum < N) {
			if (end == num_size) break;
			cur_sum += num[end++];

		}

		if (cur_sum == N) res++;
		
	}

	cout << res << "\n";
	return 0;
}