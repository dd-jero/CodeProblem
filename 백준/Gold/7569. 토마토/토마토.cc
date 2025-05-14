#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos {
	int height;
	int x;
	int y;
};

int H, N, M, change_cnt = 0, day_cnt = -1; // 높이 세로 가로 익지 않은 토마토 수 최소 일수 
vector<vector<vector<int>>> box; // 상자
queue<pos> q;

// 앞,뒤,좌,우,상,하
int dz[6] = { 1,-1,0,0,0,0 };
int dx[6] = { 0,0,0,0,-1,1 };
int dy[6] = { 0,0,-1,1,0,0 };

void BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> M >> N >> H;
	box.resize(H, vector<vector<int>>(N, vector<int>(M))); // [높이][세로][가로]

	// 1: 익은 토마토, 0: 익지 않은 토마토, -1: 토마토X
	for (int h = 0;h < H;h++) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				cin >> box[h][i][j];
				
				if (box[h][i][j] == 1) { // 초기 익은 토마토 큐 삽입 
					q.push({ h,i,j });
				}
				else if (box[h][i][j] == 0) { // 익지 않은 토마토면
					change_cnt++;
				}
			}
		}
	}

	BFS();

	if (change_cnt != 0) cout << -1 << "\n";
	else cout << day_cnt << "\n";

	return 0;
}

void BFS() {

	while (!q.empty()) { // 더 이상 익지 않은 토마토 없으면 종료 

		// 하루마다 인접 토마토 익음
		int q_size = q.size();
		day_cnt++;

		for (int i = 0;i < q_size;i++) {
			auto cur = q.front();
			q.pop();

			for (int d = 0;d < 6;d++) { // 6방향 확인
				int nxt_h = cur.height + dz[d];
				int nxt_x = cur.x + dx[d];
				int nxt_y = cur.y + dy[d];

				if (nxt_h < 0 || nxt_h >= H || nxt_x < 0 || nxt_x >= N || nxt_y < 0 || nxt_y >= M) continue; // 범위 초과

				if (box[nxt_h][nxt_x][nxt_y] == 0 ) { // 익지 않은 토마토이면 
					q.push({ nxt_h, nxt_x, nxt_y });
					box[nxt_h][nxt_x][nxt_y] = 1; // 토마토 익음.
					change_cnt--;
				}
			}
		}
	}
}
