#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, I; // 테케 수, 체스판 한 변의 길이 
int init_x, init_y; // 초기 나이트 위치
int dest_x, dest_y; // 이동하려는 위치 
vector<vector<int>> visited; // 해당 위치 접근하는 최소 이동 수 

int dx[8] = { -2,-2,-1,1,2,2,1,-1 };
int dy[8] = { -1,1,2,2,1,-1,-2,-2 };

void BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	for (int t = 0;t < T;t++) {
		cin >> I;
		visited.assign(I, vector<int>(I, 0)); // 방문 체크 초기화 
		cin >> init_x >> init_y >> dest_x >> dest_y;

		BFS();

		cout << visited[dest_x][dest_y] << "\n";
	} 
	return 0;
}

void BFS() {
	queue<pair<int,int>> q;

	// 나이트의 초기 위치 
	q.push({ init_x, init_y});
	visited[init_x][init_y] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.first == dest_x && cur.second == dest_y) return; 

		for (int d = 0;d < 8;d++) {
			int nxt_x = cur.first + dx[d];
			int nxt_y = cur.second + dy[d];

			if (nxt_x < 0 || nxt_x >= I || nxt_y < 0 || nxt_y >= I) continue; // 범위 초과
			if (visited[nxt_x][nxt_y] > 0) continue; // 이전에 방문했으면

			q.push({nxt_x,nxt_y});
			visited[nxt_x][nxt_y] = visited[cur.first][cur.second] + 1;
		}

	}
}