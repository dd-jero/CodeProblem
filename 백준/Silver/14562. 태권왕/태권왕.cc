#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct cur_count {
	int cnt;
	int s_score;
	int t_score;

	bool operator>(const cur_count& other) const {
		return cnt > other.cnt;
	}
};

int c; // 테케 수
int s, t, res;
void bfs(cur_count count);
priority_queue<cur_count, vector<cur_count>, greater<cur_count>> pq; // 오름차순 우선순위 큐

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> c;

	for (int i = 0;i < c;i++) {
		cin >> s >> t;
		pq = priority_queue<cur_count, vector<cur_count>, greater<cur_count>>(); // 초기화
		res = 2e9; // 초기화
		bfs(cur_count{0,s,t});
		cout << res << "\n";
	}

	return 0;
}

void bfs(cur_count count) {
	pq.push(count);
	set<pair<int, int>> visited;
	visited.insert({count.s_score, count.t_score});

	while (!pq.empty()) {
		int cur_s = pq.top().s_score;
		int cur_t = pq.top().t_score;
		int cur = pq.top().cnt;
		pq.pop();

		if (cur_s > cur_t) continue; // 이기고 있는 상황이면 어떤 경우든 더 같아질 수 없기 때문에 pass

		if (cur_s == cur_t) { // 종료 조건: 점수 동일하면 
			res = res > cur ? cur : res;
			return;
		}

		if (visited.count({ cur_s * 2, cur_t + 3 }) == 0) {
			pq.push(cur_count{ cur + 1, cur_s * 2, cur_t + 3 }); // A의 경우
			visited.insert({ cur_s * 2, cur_t + 3 });

		}
		if (visited.count({ cur_s + 1, cur_t }) == 0) {
			pq.push(cur_count{ cur + 1, cur_s + 1, cur_t }); // B의 경우
			visited.insert({ cur_s + 1, cur_t });
		}
	}
}