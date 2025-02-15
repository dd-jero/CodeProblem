#include <iostream>
using namespace std;

int N, X, max_visitors = 0, cnt;
int arr[250001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> X;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	int start = 0;
	int tmp_visitors = 0;

	for (int i = 0;i < X;i++) {
		max_visitors += arr[i];
	}

	tmp_visitors = max_visitors;
	cnt = 1;

	for (int i = X;i < N;i++) {
		tmp_visitors -= arr[start++];
		tmp_visitors += arr[i];

		if (max_visitors < tmp_visitors) {
			max_visitors = tmp_visitors;
			cnt = 1;
		}
		else if (max_visitors == tmp_visitors) {
			cnt++;
		}
	}

	if (max_visitors == 0) {
		cout << "SAD" << "\n";
	}
	else {
		cout << max_visitors << "\n" << cnt << "\n";
	}
	return 0;
}