#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N, blue_cnt = 0, not_cnt = 0, cnt = 0;
vector<vector<char>> region;
vector<vector<bool>> visited;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void BFS(int x, int y, char color, bool check);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	region.resize(N, vector<char> (N));
	visited.resize(N, vector<bool>(N));

	string str;
	for (int i = 0;i < N;i++) {
		cin >> str;
		for (int j = 0;j < N;j++) {
			region[i][j] = str[j];
		}
	}

	// 적록색약 아닌 사람
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (region[i][j] == 'B' && !visited[i][j]) {
				BFS(i, j, 'B', false);
				blue_cnt++;
			}

			if (region[i][j] == 'R' && !visited[i][j]) {
				BFS(i, j, 'R', false);
				not_cnt++;
			}

			if (region[i][j] == 'G' && !visited[i][j]) {
				BFS(i, j, 'G', false);
				not_cnt++;
			}
		}
	}

	visited.assign(N, vector<bool>(N, false));

	// 적록색약
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (region[i][j] == 'R' || region[i][j] == 'G') {
				if (!visited[i][j]) {
					BFS(i, j, 'R', true);
					cnt++;
				}
			}
		}
	}

	cout << blue_cnt + not_cnt << " " << blue_cnt + cnt << "\n";

	return 0;
}

void BFS(int x, int y, char color, bool check) { // true면 적록색약, false면 아님
	queue<pair<int, int>> q; 
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int d = 0;d < 4;d++) {
			int nxt_x = cur.first + dx[d];
			int nxt_y = cur.second + dy[d];

			if (nxt_x < 0 || nxt_x >= N || nxt_y < 0 || nxt_y >= N) continue; // 범위 초과시

			if (!check) { // 적록색약 아닌 사람
				if (region[nxt_x][nxt_y] == color) {
					if (!visited[nxt_x][nxt_y]) {
						q.push({ nxt_x,nxt_y });
						visited[nxt_x][nxt_y] = true;
					}
				}
			}
			else { // 적록색약인 사람
				if (region[nxt_x][nxt_y] == color || region[nxt_x][nxt_y] == 'G') {
					if (!visited[nxt_x][nxt_y]) {
						q.push({ nxt_x,nxt_y });
						visited[nxt_x][nxt_y] = true;
					}
				}
			}
			
		}

	}

}