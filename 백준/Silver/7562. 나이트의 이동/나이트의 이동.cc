#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info {
	int x;
	int y;
	int cnt; // 이동 횟수

	bool operator<(const Info& other) const {
		return this->cnt > other.cnt; // 이동 횟수 오름차순 
	}
};

int T, I; // 테케 수, 체스판 한 변의 길이 
int init_x, init_y; // 초기 나이트 위치
int dest_x, dest_y; // 이동하려는 위치 
vector<vector<bool>> visited; // 방문 체크

int dx[8] = { -2,-2,-1,1,2,2,1,-1 };
int dy[8] = { -1,1,2,2,1,-1,-2,-2 };

int BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	for (int t = 0;t < T;t++) {
		cin >> I;
		visited.assign(I, vector<bool>(I, false)); // 방문 체크 초기화 
		cin >> init_x >> init_y >> dest_x >> dest_y;

		int res = BFS();

		cout << res << "\n";

		visited.clear();

	} 
	return 0;
}

int BFS() {
	priority_queue<Info> pq;

	// 나이트의 초기 위치 
	pq.push({ init_x, init_y, 0 });
	visited[init_x][init_y] = true;

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (cur.x == dest_x && cur.y == dest_y) return cur.cnt; // 목표 위치 도착

		for (int d = 0;d < 8;d++) {
			int nxt_x = cur.x + dx[d];
			int nxt_y = cur.y + dy[d];

			if (nxt_x < 0 || nxt_x >= I || nxt_y < 0 || nxt_y >= I) continue; // 범위 초과

			if (!visited[nxt_x][nxt_y]) { // 아직 방문 안했으면 
				pq.push({ nxt_x,nxt_y,cur.cnt + 1 });
				visited[nxt_x][nxt_y] = true;
			}
		}

	}
}