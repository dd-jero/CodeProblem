#include <iostream>
using namespace std;

int num, max_idx, max_num = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	for (int i = 1;i <= 9;i++) {
		cin >> num;

		if (max_num < num) {
			max_idx = i;
			max_num = num;
		}
	}

	cout << max_num << "\n";
	cout << max_idx << "\n";

	return 0;
}