#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int x;
	int y;
	int len;
};

int n, m, cnt, res = 0; // 시작위치에서의 가장 가까운 안전 거리, 안전거리의 최댓값
int map[51][51];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
vector<vector<int>> visited;
void bfs(int start_x, int start_y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			int num;
			cin >> num;

			if (num == 1) { // 상어 위치 
				map[i][j] = -1;
			}
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (map[i][j] == -1) { // 상어 위치면 
				bfs(i, j);
			}
		}
	}

	for (int i = 0;i < n;i++) { // 안전 거리 최댓값 
		for (int j = 0;j < m;j++) {
			if (map[i][j] > res) res = map[i][j];
		}
	}

	cout << res << "\n";

	return 0;
}

void bfs(int start_x, int start_y) {

	vector<vector<bool>> visited(n, vector<bool>(m, false)); // 현재 출발한 상어에 위치 기준에서의 방문 체크 
	queue<node> q;
	q.push(node{start_x, start_y, 0});
	visited[start_x][start_y] = true;
	cnt = 0;

	while (!q.empty()) {

		int cur_x = q.front().x;
		int cur_y = q.front().y;
		int cur_len = q.front().len;
		q.pop();

		for (int i = 0;i < 8;i++) {
			int nxt_x = cur_x + dx[i];
			int nxt_y = cur_y + dy[i];

			if (-1 < nxt_x && nxt_x < n && -1 < nxt_y && nxt_y < m) {
				if (!visited[nxt_x][nxt_y]) {
					if (map[nxt_x][nxt_y] != -1) { // 빈 칸이면 
						if (map[nxt_x][nxt_y] == 0) { // 첫 방문 시
							map[nxt_x][nxt_y] = cur_len + 1;
						}
						else { // 이미 방문했으면
							map[nxt_x][nxt_y] = map[nxt_x][nxt_y] > cur_len + 1 ? cur_len + 1 : map[nxt_x][nxt_y];
						}

						// 다음 이동 위해 삽입 
						q.push(node{ nxt_x,nxt_y,map[nxt_x][nxt_y] });
						visited[nxt_x][nxt_y] = true;
					}
				}
				
			}
		}
	}
}