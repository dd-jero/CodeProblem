#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int max_val = 0, idx_x, idx_y;

	for (int i = 1;i <= 9;i++) {
		for (int j = 1;j <= 9;j++) {
			int num;
			cin >> num;

			if (max_val <= num) {
				max_val = num;
				idx_x = i;
				idx_y = j;
			}
		}
	}

	cout << max_val << "\n" << idx_x << " " << idx_y;
	return 0;
}