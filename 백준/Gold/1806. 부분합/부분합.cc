#include <iostream>
using namespace std;

int numbers[100001];

int main() {

	int N, S, res = 100001; // 수얼의 길이, 합의 기준
	cin >> N >> S;

	int num;
	for (int i = 0;i < N;i++) {
		cin >> num;
		numbers[i] = num;
	} // 입력 완료

	// 투포인터 
	int start_idx = 0, end_idx = 0, tmp_sum = 0;
	while (true) {
		if (tmp_sum >= S) { // 기준보다 크면

			tmp_sum -= numbers[start_idx++];
			res = res > (end_idx - start_idx + 1) ? (end_idx - start_idx + 1) : res;
		}
		else if (end_idx == N) {
			break;
		}
		else {
			tmp_sum += numbers[end_idx++];
		}
	}

	if (res == 100001) { // 합을 만드는 것이 불가능 하면 
		cout << 0;
	}
	else {
		cout << res;

	}

	return 0;
}