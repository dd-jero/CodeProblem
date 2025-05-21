#include <iostream>
#include <vector>
#include <cmath>

int N, res = 0, sum = 0;
std::vector<int> numbers;
std::vector<bool> prime;

void IsPrime(int n);

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	prime.resize(N + 1);

	IsPrime(N);

	for (int i = 2;i <= N;i++) {
		if (!prime[i]) numbers.push_back(i);
	}

	int start = 0;
	int end = 0;
	int num_size = numbers.size();

	while (1) {
		if (sum >= N) { // 구하고자 하는 수 보다 크거나 같으면
			if (sum == N) res++;  // 같으면 
			sum -= numbers[start++]; // start 요소 빼고 인덱스 증가 
		}
		else { // 작으면 
			if (end == num_size) break; // 범위 초과 시 종료
			sum += numbers[end++]; // end 요소 더하고 인덱스 증가  
		}
	}

	std::cout << res << "\n";
	return 0;
}

void IsPrime(int n) {

	for (int i = 2;i <= sqrt(n);i++) { // i*i부터 판별해서 루트 n까지만 돌면 됨. 
		if (prime[i]) continue; // 이미 소수가 아니면

		for (int j = i * i; j <= n;j += i) {
			prime[j] = true;
		}
	}
}