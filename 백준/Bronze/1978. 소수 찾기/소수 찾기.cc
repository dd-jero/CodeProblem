#include <iostream>
#include <cmath>
using namespace std;

int N, res = 0, numbers[101];
bool not_prime[1001]; // true: 소수 아님 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	
	for (int i = 0;i < N;i++) {
		cin >> numbers[i];
	}

	not_prime[0] = true;
	not_prime[1] = true; 

	for (int i = 2;i <= sqrt(1000);i++) {
		if (not_prime[i]) continue;

		for (int j = i * i; j <= 1000;j += i) {
			not_prime[j] = true;
		}
	}

	for (int i = 0;i < N;i++) {
		if (!not_prime[numbers[i]]) res++;
	}

	cout << res << "\n";
	return 0;
}