#include <iostream>
using namespace std;

int main(void)
{
	int M, N, min_num = 10001, sum = 0;

	cin >> M >> N;

	for (int num = M; num <= N;num++) {

		for (int i = 2;i <= num;i++) {
			if (i == num) { // 해당 수가 소수이면
				min_num = min_num > num ? num : min_num;
				sum += num;
				break;
			}

			if (num % i == 0) { // 해당 수가 소수가 아니면 for문 종료
				break;
			}
		}
	}

	if (sum == 0) {
		cout << -1;
	}
	else {
		cout << sum << "\n" << min_num;
	}

	return 0;
}