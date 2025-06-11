#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
long long numbers[100001], check[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	// 주어지는 수 입력 
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> numbers[i];
	}

	// 이분 탐색 위한 정렬 
	sort(numbers, numbers + N);

	// 찾고자 하는 수 입력
	cin >> M;
	for (int i = 0;i < M;i++) {
		cin >> check[i];
	}

	// 찾고자 하는 수마다 이분 탐색 
	for (int i = 0;i < M;i++) {
		long long cur = check[i];
		int start = 0;
		int end = N - 1;
		bool find = false;

		while (start <= end) {
			int mid = (start + end) / 2;

			// mid 요소가 찾는 숫자보다 클 때
			if (numbers[mid] > cur) end = mid - 1;

			// mid 요소가 찾는 숫자보다 작을 때
			else if (numbers[mid] < cur) start = mid + 1;

			// 찾았을 때 
			else {
				find = true;
				break;
			}
		}

		if (find) cout << 1 << "\n";
		else cout << 0 << "\n";

	}
	

	return 0;
}