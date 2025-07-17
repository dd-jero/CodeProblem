#include <iostream>
using namespace std;

int small, big;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b;
	cin >> a >> b;

	if (a > b) small = b, big = a;
	else small = a, big = b;

	// 작은 수의 약수 구하고 큰 수부터 시도
	for (int i = small;i > 0;i--) {
		if (small % i == 0) {
			if (big % i == 0) {
				cout << i << "\n";
				break;
			}
		}
	}

	// 큰 수의 배수를 통해서 작은 수의 배수 여부 확인 
	int mul = 1;
	while (1) {
		if ((big * mul) % small == 0) {
			cout << big * mul << "\n";
			break;
		}

		mul++;
	}



	return 0;
}