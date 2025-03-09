#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, res; // N개의 수, 차이가 M이상이면서 제일 작은 경우
vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	int num;
	for (int i = 0;i < N;i++) {
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
	res = vec[N - 1] - vec[0];
	int start = 0, end = 0;

	while (end < N) {
		
		int diff = vec[end] - vec[start];

		if (diff >= M) { // 차이가 M 이상이면
			res = res > diff ? diff : res;
			start++;
			
		}
		else { // 차이가 M 미만이면
			end++;
		}

		if (start > end) {
			end = start;
		}
		
	}

	cout << res << "\n";
	return 0;
}