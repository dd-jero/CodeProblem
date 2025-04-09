#define INF 2e9
#include <iostream>
#include <vector>
using namespace std;

int N, K, res = INF;// 집 개수, 대피소 개수, 결과 
vector<pair<int, int>> home;
vector<bool> check;
void Recur(int idx, int cnt);
void Cal_distance();

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> N >> K;
	int x, y;
	for (int i = 0;i < N;i++) {
		cin >> x >> y;
		home.push_back({ x,y });
	}

	check.resize(N);

	Recur(0, 0);
	cout << res << "\n";

	return 0;
}

void Recur(int idx, int cnt) { // K개의 대피소 위치 지정

	// K개가 다 지정되면 거리 구하기
	if (cnt == K) {
		Cal_distance();
		return;
	}

	for (int i = idx; i < N;i++) {

		// 해당 집을 대피소로
		check[i] = true;
		Recur(i + 1, cnt + 1);

		// 원복
		check[i] = false;
	}
}

void Cal_distance() {

	// 집에서 가장 가까운 대피소로 이동할 때 가장 긴 거리가 최소 되도록
	int max_dis = 0;

	for (int h = 0; h < N;h++) { // 각 집에서 가장 가까운 대피소와의 거리 구하기
		int cur_min = INF; 
		if (check[h]) continue; // 해당 집이 대피소면 건너뜀

		for (int i = 0;i < N;i++) {
			if (check[i]) { // 해당 집이 대피소면
				int dis = abs(home[h].first - home[i].first) + abs(home[h].second - home[i].second);
				cur_min = cur_min > dis ? dis : cur_min;
			}
		}

		// 현재 집에서 가장 가까운 거리가 길면
		max_dis = max_dis < cur_min ? cur_min : max_dis;
	}

	res = max_dis < res ? max_dis : res;
}
