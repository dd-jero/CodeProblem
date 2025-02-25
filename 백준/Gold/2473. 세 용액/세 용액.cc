#define INF 3000000000
#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long res = INF;
long long arr[5001], ans[3];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	// 오름차순 정렬 
	sort(arr, arr + N);

	for (int m = 0;m < N-2;m++) {
		int start = m + 1, end = N - 1; // m 다음 위치부터 시작 시점
		while (start < end) {

			if (start == m || end == m) continue;

			int mid = (start + end) / 2;
			long long cur_sum = arr[start] + arr[end] + arr[m];

			if (cur_sum == 0) { // 세 용액의 합이 0이면
				ans[0] = arr[m];
				ans[1] = arr[start];
				ans[2] = arr[end];
				break;
			}
			else { // 세 용액의 합이 0이 아니면 

				if (abs(cur_sum) < res) { // 0에 더 가까우면 갱신 
					res = abs(cur_sum);
					ans[0] = arr[m];
					ans[1] = arr[start];
					ans[2] = arr[end];
				}

				if (cur_sum < 0) { // 합이 음수이면
					start++; // 시작 위치 증가 
				}
				else { // 합이 양수이면 
					
					end--; // 끝 위치 증가 
				}
			}
		}
	}

	for (int i = 0;i < 3;i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}