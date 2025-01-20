#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node {
	int x;
	int y;
};

int n, m, k; // 행, 렬, 1초 이동 가능 최대칸, 최소 시간
int s_x, s_y, e_x, e_y;
int gym[1001][1001]; 
int visited[1001][1001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue<Node> q;

int bfs();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visited[i][j] = 2e9;
		}
	}

	string str;
	for (int i = 1;i < n+1;i++) {
		cin >> str;
		for (int j = 1;j < m+1;j++) {
			if (str[j-1] == '#') gym[i][j] = 1; // 벽
		}
	}

	// 시작, 도착 위치 
	cin >> s_x >> s_y >> e_x >> e_y;

	int res = bfs();
	cout << res << "\n";

	return 0;
}

int bfs() {
	q.push(Node{ s_x, s_y });
	visited[s_x][s_y] = 0;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		// 종료 조건: 목적지 도착 
		if (cur.x == e_x && cur.y == e_y) {
			return visited[cur.x][cur.y];
		}

		for (int dir = 0; dir < 4; dir++) { // 4방향에 대해서
			for (int step = 1; step <= k; step++) { // 최대 이동 가능한 만큼
				int nx = cur.x + dx[dir] * step;
				int ny = cur.y + dy[dir] * step;

				if (nx < 1 || nx > n || ny < 1 || ny > m || gym[nx][ny] == 1) break; // 다음 위치로 이동 불가능 하면 해당 방향 이동 종료 

				if (visited[nx][ny] > visited[cur.x][cur.y] + 1) { // 첫 방문이거나 현재 방문 시간 + 1보다 다음 위치 방문했던 시간이 클때 
					visited[nx][ny] = visited[cur.x][cur.y] + 1;
					q.push(Node{ nx, ny });
				}
				else if (visited[nx][ny] < visited[cur.x][cur.y] + 1) { // 다음 위치 방문 시간이 더 작으면 
					break;
				}
			}
		}
	}
	return -1;
}