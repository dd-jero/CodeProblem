#include <iostream>
#include <algorithm>
using namespace std;

int length[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (1) {
		for (int i = 0; i < 3; i++) {
			cin >> length[i];
		}

		if (length[0] == 0 && length[1] == 0 && length[2] == 0) break;

		sort(length, length + 3);

		if (length[2] * length[2] == (length[0] * length[0] + length[1] * length[1])) cout << "right" << "\n";
		else cout << "wrong" << "\n";

	}

	return 0;
}