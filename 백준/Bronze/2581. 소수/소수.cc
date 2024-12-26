#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(void)
{
	int M, N;
	vector<int> vec;

	cin >> M >> N;

	for (int num = M; num <= N;num++) {

		for (int i = 2;i <= num;i++) {
			if (i == num) { // 해당 수가 소수이면
				vec.push_back(num);
				break;
			}

			if (num % i == 0) { // 해당 수가 소수가 아니면 for문 종료
				break;
			}
		}
	}

	if (vec.size() == 0) {
		cout << -1;
	}
	else {
		sort(vec.begin(), vec.end());
		int sum = accumulate(vec.begin(), vec.end(), 0);

		cout << sum << "\n" << vec[0];
	}

	return 0;
}