#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n_A, n_B;
vector<int> vec_A, vec_B, res;
vector<bool> check; // true: 집합 A와 집합 B에 모두 존재 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n_A >> n_B;

	vec_A.resize(n_A);
	vec_B.resize(n_B);
	check.resize(n_A);

	for (int i = 0;i < n_A;i++) {
		cin >> vec_A[i];
	}

	for (int i = 0;i < n_B;i++) {
		cin >> vec_B[i];
	}

	sort(vec_B.begin(), vec_B.end());

	for (int i = 0;i < n_A;i++) { // 집합 A의 원소를 하나씩 확인
		
		int start = 0;
		int end = n_B - 1;

		if (vec_A[i] < vec_B[start]) continue;
		if (vec_A[i] > vec_B[end]) continue;

		while (start <= end) {
			int mid = (start + end) / 2;

			if (vec_A[i] > vec_B[mid]) start = mid + 1;
			else if (vec_A[i] < vec_B[mid]) end = mid - 1;
			else { // 집합 B에서 찾으면 루프 종료 
				check[i] = true;
				break;
			}
		}
	}

	for (int i = 0;i < check.size();i++) {
		if (!check[i]) res.push_back(vec_A[i]);
	}

	if (res.size() == 0) cout << 0 << "\n";
	else {
		cout << res.size() << "\n";
		sort(res.begin(), res.end());

		for (int n: res) {
			cout << n << " ";
		}
		cout << "\n";
	}

	return 0;
}