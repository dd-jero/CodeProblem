#include <iostream>
using namespace std;

double A, B; // float의 정밀도는 6 ~ 9 자리이기 때문에 문제 조건(절대오차 또는 상대오차가 10^-9 이하) 성립 X

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> A >> B;

	cout.precision(12);
	cout << fixed;

	cout << A / B << "\n";

	return 0;
}