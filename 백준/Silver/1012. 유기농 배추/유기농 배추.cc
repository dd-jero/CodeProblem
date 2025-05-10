#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, M, N, K; // 테케 수, 가로, 세로, 배추 심어진 위치 개수 
vector<vector<int>> farm;
vector<vector<bool>> visited;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void BFS(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> T;

	for (int i = 0;i < T;i++) {
		cin >> M >> N >> K;

		// 매 테케 마다 초기화 
		farm.assign(N, vector<int>(M, 0));
		visited.assign(N, vector<bool>(M, false));
		int res = 0; // 배추흰지렁이 개수

		int x, y;
		for (int i = 0;i < K;i++) { // 배추 심어진 위치 
			cin >> y >> x; // 문제에서 가로, 세로 위치로 주어짐!!
			farm[x][y] = 1;
		}

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (farm[i][j] == 1 && !visited[i][j]) { // 방문하지 않은 배추 위치면
					BFS(i, j);
					res++;
				}
			}
		}

		cout << res << "\n";

		farm.clear();
		visited.clear();
	}

	return 0;
}

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int d = 0;d < 4;d++) // 상하좌우
		{
			int nxt_x = cur.first + dx[d];
			int nxt_y = cur.second + dy[d];

			if (nxt_x < 0 || nxt_x >= N || nxt_y < 0 || nxt_y >= M) continue; // 범위 초과

			if (farm[nxt_x][nxt_y] == 1) { // 배추의 위치면
				if (!visited[nxt_x][nxt_y]) { // 방문 하지 않았을 때 
					q.push({ nxt_x, nxt_y });
					visited[nxt_x][nxt_y] = true;
				}
			}
		}
	}

}