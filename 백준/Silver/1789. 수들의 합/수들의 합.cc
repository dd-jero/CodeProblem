#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	unsigned int S; // int 범위가 약 -21억 ~ 약 21억
	unsigned int res = 0;

	cin >> S;

	for (int i = 1;i <= S;i++) {

		if (S - i >= 0) {

			S -= i;
			res++;

			if (S - i == 0) { // 종료 조건 
				break;
			}
		}
	}

	cout << res;

	return 0;
}