#include <iostream>
using namespace std;

int n, m;
int money[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		cin >> money[i];
	}

	int k, low = 0;
	int high = 1000000000; // 최대 N * i번째 날 이용할 최대 금액 

	while (low <= high) {
		int cnt = 0;
		int mid = (low + high) / 2;
		int tmp = 0;
		bool flag = false;

		for (int i = 0;i < n;i++) {
			if (money[i] > mid) { // 
				low = mid + 1;
				flag = true;
			}
			 
			if (tmp >= money[i]) { // 남은 돈으로 충족 가능
				tmp -= money[i];
			}
			else { // 새로운 인출이 필요한 경우
				tmp = mid - money[i];
				cnt++;
			}
		}

		if (flag) continue; // 현재 mid 값이 최소 인출 금액으로 적합하지 않으면 

		if (cnt > m) { // 인출 횟수가 초과되면 
			low = mid + 1;
		}
		else { // 출금 횟수가 남으면 
			high = mid - 1; 
			k = mid; // 최소 인출 금액 업데이트 
		}
	}

	cout << k << "\n";

	return 0;
}