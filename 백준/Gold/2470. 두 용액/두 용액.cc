#define INF 2e9
#include <iostream>
#include <algorithm>
using namespace std;


// 산성 또는 알칼리로만 입력이 주어질 수 있음 => 두 용액의 합이 최소 -20억, 최대 20억 => int형으로 가능
int n, tmp = INF;
int arr[100001], res[2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int start = 0, end = n - 1;
	while (start < end) {

		int cur_sum = arr[start] + arr[end];

		if (cur_sum == 0) { // 합이 0이 되면 바로 루프 종료
			res[0] = arr[start]; res[1] = arr[end];
			break;
		}
		else { // 합이 0이 아닐 경우 

			if (cur_sum < 0) { // 두 합이 0보다 작으면 

				if (abs(cur_sum) < tmp) { // 0에 더 가까우면 
					res[0] = arr[start]; res[1] = arr[end];
					tmp = abs(cur_sum);
				}

				start++;
				
			}
			else{ // 0보다 크면 

				if (cur_sum < tmp) { // 0에 더 가까우면 
					res[0] = arr[start]; res[1] = arr[end];
					tmp = cur_sum;
				}

				end--;
			}
		}

	}

	cout << res[0] << " " << res[1] << "\n";

	return 0;
}