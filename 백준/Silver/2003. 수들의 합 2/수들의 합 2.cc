#include <iostream>
using namespace std;

int N, M, res = 0; // N개의 수로 된 수열, M이 되는 경우의 수
int numbers[10001]; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		cin >> numbers[i];
	}

	int left = 0, right = 0;
	int sum = numbers[left];

	while (right < N) {

		if (sum == M) { // M 동일
			res++;
			sum += numbers[++right]; // right 포인터 증가 => N 이상되면 루프문 종료 (더 이상 M이 나올 경우가 없음)
		}
		else if (sum < M) { // M 미만

			sum += numbers[++right];
		}
		else if (sum > M) { // M 초과
			sum -= numbers[left++];
		}
	}

	cout << res << "\n";

	return 0;
}