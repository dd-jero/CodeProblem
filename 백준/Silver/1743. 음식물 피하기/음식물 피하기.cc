#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> map; 
vector<vector<bool>> visited;
queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, k, x, y, cnt = 0, res = 0; // 세로, 가로, 음식물 쓰레기 개수
void bfs(int x, int y);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	map.resize(n + 1, vector<int>(m+1,0));
	visited.resize(n + 1, vector<bool>(m + 1, false));

	for (int i = 0;i < k;i++) {
		cin >> x >> y;
		map[x-1][y-1] = 1; // 쓰레기가 존재하는 위치에 1
	}


	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (!visited[i][j] && map[i][j] == 1) { // 해당 좌표를 방문하지 않았고 쓰레기 위치면
				cnt = 1;
				bfs(i, j);
				res = res < cnt ? cnt : res;
			}
		}
	}

	cout << res << "\n";
	return 0;
}

void bfs(int x, int y) {

	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nxt_x = cur_x + dx[i];
			int nxt_y = cur_y + dy[i];

			if (-1 < nxt_x && nxt_x < n && -1 < nxt_y && nxt_y < m) { // 범위 내 존재시
				if (!visited[nxt_x][nxt_y] && map[nxt_x][nxt_y] == 1) { // 방문하지 않았고 쓰레기 위치여야
					q.push(make_pair(nxt_x, nxt_y));
					visited[nxt_x][nxt_y] = true;
					cnt++;
				}
			}
		}
	}


}