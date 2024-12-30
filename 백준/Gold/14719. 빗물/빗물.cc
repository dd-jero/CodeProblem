#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int H, W, res = 0;

	cin >> H >> W;

	vector<int> vec(W, 0);

	for (int i = 0;i < W;i++) {
		int num;
		cin >> num;
		vec[i] = num;
	}

	for (int i = 1;i < W - 1;i++) {
		int tmp, left_max = 0, right_max = 0;
		// 현재 열 기준 왼쪽에서의 max
		for (int left = 0;left < i;left++) {
			left_max = left_max < vec[left] ? vec[left] : left_max;
		}

		// 현재 열 기준 오른쪽에서의 max
		for (int right = i + 1;right < W;right++) {
			right_max = right_max < vec[right] ? vec[right] : right_max;
		}

		tmp = left_max > right_max ? right_max : left_max;

		if (tmp > vec[i]) { // 해당 작은 값이 현재 열의 1의 수보다 작아야
			res += (tmp - vec[i]);
		}

	}

	cout << res; 

	return 0;
}