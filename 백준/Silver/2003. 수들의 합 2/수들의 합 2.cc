#include <iostream>
using namespace std;

int arr[10001];
int res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M; // 수의 개수, 목표 합

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	int start = 0, end = 0;
	int sum = 0;

	while(1) {

		if (sum >= M) { // 목표 값보다 크거나 같으면
			sum -= arr[start++];
		}
		else if (end == N) {
			break;
		}
		else {  // 목표 값보다 작으면
			sum += arr[end++];
		}

		if (sum == M) res++;
	}

	cout << res << "\n";

	return 0;
}