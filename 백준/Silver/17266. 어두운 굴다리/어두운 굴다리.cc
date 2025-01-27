#define INF 2e9
#include <iostream>
#include <cmath>
using namespace std;

int n, m; // 굴다리 길이, 가로등 개수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	double prev = 0, cur = 0, min_height = INF;
	for (int i = 0;i < m;i++) {
		cin >> cur;

		if (i == 0) { // 첫 위치의 가로등 이면
			min_height = cur;
		}
		else { // 이전 가로등과의 겹치는 부분을 고려 
			min_height = ceil((cur - prev) / 2) > min_height ? ceil((cur - prev) / 2) : min_height;
		}

		prev = cur;
	}
	// 마지막 위치 가로등이면 추가적으로 오른쪽 부분을 확인
	min_height = (n - cur) > min_height ? n - cur : min_height;


	cout << min_height << "\n";

	return 0;
}