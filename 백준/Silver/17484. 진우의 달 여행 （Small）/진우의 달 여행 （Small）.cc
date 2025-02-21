#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Node {
	int x;
	int y;
	int fuel; // 현재위치까지 사용한 연료 합
	int prev_dir; // 이전 이동 방향 (-1: 이전 이동 없음, 0: 좌하, 1: 하, 2: 우하)

	bool operator<(const Node& other) const { // 연료 합 오름차순 
		return this->fuel < other.fuel;
	}
};

int N, M, res = INT_MAX;
int fuels[9][9];
int dx[3] = { 1,1,1 };
int dy[3] = { -1,0,1 };

void bfs(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	
	// 0행: 지구, N+1행: 달 
	for (int i = 1;i < N + 1;i++) {
		for (int j = 0;j < M;j++) {
			cin >> fuels[i][j];
		}
	}

	for (int i = 0;i < M;i++) {
		bfs(0, i); // 0행의 모든 위치에서 시작 고려 
	}

	cout << res << "\n";

	return 0;
}

void bfs(int x, int y) {
	priority_queue<Node> pq;
	pq.push(Node{ x, y, 0, -1 });
	
	while (!pq.empty()) {
		Node cur = pq.top();
		pq.pop();

		// 달에 도착
		if (cur.x == N + 1) {
			res = cur.fuel < res ? cur.fuel : res; // 최소 연료 갱신 
		}

		for (int i = 0;i < 3;i++) {
			if (cur.prev_dir == i) continue; // 이전 이동 방향과 동일하면 지나감!

			int nxt_x = cur.x + dx[i];
			int nxt_y = cur.y + dy[i];

			if (-1 < nxt_x && nxt_x < N + 2 && -1 < nxt_y && nxt_y < M) {
				pq.push(Node{ nxt_x, nxt_y, cur.fuel + fuels[nxt_x][nxt_y], i });
			}
		}
	}

}