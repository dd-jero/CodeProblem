#include <iostream>
#include <algorithm>
using namespace std;

int n, x, res = 0;
int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	cin >> x;

	// 오름 차순 정렬
	sort(arr, arr + n);

	// 투 포인터 
	int start = 0, end = n - 1;
	while (start < end) {

		if (arr[start] + arr[end] == x) { // x 와 같으면 
			start++;
			end--;
			res++;
		}
		else if (arr[start] + arr[end] < x) { // x 보다 작으면 
			start++;
		}
		else { // x 보다 크면 
			end--;
		}
	}

	cout << res << "\n";

	return 0;
}