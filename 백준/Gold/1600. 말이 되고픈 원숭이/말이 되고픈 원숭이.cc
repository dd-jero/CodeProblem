#include <iostream>
#include <queue>
using namespace std;

struct Info {
	int x;
	int y;
	int move_cnt;
	int jump_cnt;
};

int K, W, H; // 말처럼 움직일 수 있는 횟수, 가로 길이, 세로길이 
int map[201][201];
int dx[12] = { 0,0,1,-1,-2,-1,1,2,2,1,-1,-2 };
int dy[12] = { 1,-1,0,0,-1,-2,-2,-1,1,2,2,1 };
bool visited[31][201][201];

int BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> K >> W >> H;

	for (int i = 0;i < H;i++) {
		for (int j = 0;j < W;j++) {
			cin >> map[i][j];
		}
	}

	int res = BFS();

	cout << res << "\n";

	return 0;
}

int BFS() {
	queue<Info> q;
	q.push({ 0,0,0,0 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.x == H - 1 && cur.y == W - 1) return cur.move_cnt; // 도착점 도달 
		
		int nxt_x, nxt_y, cnt = cur.move_cnt + 1, jump = cur.jump_cnt;
		for (int d = 0;d < 12;d++) {
			if (d > 3) { // 말 점프 이동 경우
				if (cur.jump_cnt >= K) continue; // 말처럼 움직일 수 없는 경우
				jump = cur.jump_cnt + 1; // 점프 카운트 증가
			}
			
			nxt_x = cur.x + dx[d];
			nxt_y = cur.y + dy[d];

			if (nxt_x < 0 || nxt_x >= H || nxt_y < 0 || nxt_y >= W) continue; // 범위 초과 (먼저 처리해야함!)
			if (map[nxt_x][nxt_y] == 1) continue; // 다음 위치가 장애물인 경우 
			if (visited[jump][nxt_x][nxt_y]) continue; // 이미 방문한 경우 

			if (nxt_x == H - 1 && nxt_y == W - 1) return cnt; // 도착점 도달 


			q.push({nxt_x, nxt_y, cnt, jump});
			visited[jump][nxt_x][nxt_y] = true;
		}
	}

	return -1; // 시작점에서 도착점까지 이동 불가능 

}