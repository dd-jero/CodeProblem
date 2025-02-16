#include <iostream>
#include <algorithm>
using namespace std;

int N, M, res = 0;
int arr[10001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	cin >> M;

	// 정렬 
	sort(arr, arr + N);

	// 2. 배정될 수 없는 경우 
	// 남은 예산으로 이분 탐색 : 0 이상 M 이하 범위
	int low = 0, high = arr[N - 1];

	while (low <= high) {

		int mid = (low + high) / 2; // 중간값 
		int sum_b = 0;

		// 현재 중간 값을 활용한 배정 예산 합 계산 
		for (int i = 0;i < N;i++) {
			sum_b += min(arr[i], mid); // 현재 중간값과 해당 위치의 예산 중 작은 값을 더함
		}

		if (M >= sum_b) { // 아직 할당할 수 있는 예산이 남으면
			res = mid;
			low = mid + 1; // 하한선 갱신
		}
		else { // 할당 예산을 초과하면
			high = mid - 1; // 상한선 갱신 
		}
		
	}

	cout << res << "\n";

	return 0;
}