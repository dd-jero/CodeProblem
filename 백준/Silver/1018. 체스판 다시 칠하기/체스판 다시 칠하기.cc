#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
using namespace std;

struct Info {
	int x;
	int y;
	int color;
};

int M, N, res = 300; // 세로, 가로 크기 
int board[51][51]; // 1: white, -1: black 
bool visited[51][51];
int dx[4] = { 0,0,1, - 1 };
int dy[4] = { 1,-1,0,0 };

void BFS(int st_x, int str_y, int str_color);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> M >> N;

	string str;
	for (int i = 0;i < M;i++) {
		cin >> str;

		for (int j = 0;j < N;j++) {
			if (str[j] == 'W') board[i][j] = 1;
			else board[i][j] = -1;
		}
	}

	// (0,0) 부터 8x8 크기만큼 확인 (시작 위치의 색깔을 두개를 기준으로 해야 
	for (int i = 0;i <= M - 8;i++) {
		for (int j = 0;j <= N - 8;j++) {
			BFS(i, j, 1); // 시작 위치 색이 흰색일 때
			BFS(i, j, -1); // 시작 위치 색이 검은색일 때 
		}
	}

	cout << res << "\n";

	return 0;
}

void BFS(int st_x, int st_y, int str_color) {
	queue<Info> q;
	bool visited[51][51] = { false, };

	q.push({ st_x, st_y, str_color });
	visited[st_x][st_y] = true;
	int end_x = st_x + 8, end_y = st_y + 8;
	int tmp_cnt = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		// 현재 위치 색이 다른 경우
		if (board[cur.x][cur.y] != cur.color) {
			tmp_cnt++;	// 다시 칠해야함.

			if (tmp_cnt > res) return; // 지금까지 구했던 최소 결과보다 크면 가지치기 
		}

		for (int d = 0;d < 4;d++) {
			int nxt_x = cur.x + dx[d];
			int nxt_y = cur.y + dy[d];

			if (nxt_x < st_x || nxt_x >= end_x || nxt_y < st_y || nxt_y >= end_y) continue; // 범위 초과
			if (visited[nxt_x][nxt_y]) continue; // 이미 방문한 경우 

			// 다음 위치는 현재 위치의 색과 달라야함. 
			q.push({ nxt_x, nxt_y, (cur.color * -1) });
			visited[nxt_x][nxt_y] = true;
		}
	}

	// 최소 결과 갱신 
	res = res > tmp_cnt ? tmp_cnt : res; 

}