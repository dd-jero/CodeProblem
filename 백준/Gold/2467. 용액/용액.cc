#include <iostream>
using namespace std;

int N;
int arr[100001];
int res[2] = { 1000000000, 1000000000 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	int start = 0, end = N - 1;

	while (start < end) {

		int cur_sum = arr[start] + arr[end];
		int cur_res = res[0] + res[1];

		if (cur_sum == 0) {
			res[0] = arr[start];
			res[1] = arr[end];
			break;
		}

		if (cur_sum < 0) {
			if (abs(cur_res) - abs(cur_sum) > 0) {
				res[0] = arr[start];
				res[1] = arr[end];
			}
			start++;
		}
		else if (cur_sum > 0) {
			if (abs(cur_res) - abs(cur_sum) > 0) {
				res[0] = arr[start];
				res[1] = arr[end];
			}
			end--;
		}
	}

	cout << res[0] <<" "<< res[1] << "\n";

	return 0;
}