#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Pos {
	int z;
	int x;
	int y;
	int time;

	bool operator<(const Pos& other) const { // 시간에 따른 오름차순의 우선순위 큐를 활용
		return this->time > other.time;
	}
};

int l, r, c, s_z, s_x, s_y, e_z, e_x, e_y;
int building[31][31][31];
bool visited[31][31][31];
int dz[6] = { 1,-1,0,0,0,0 };
int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,0,1,-1,0,0 };
void bfs();
bool is_checked(int x, int y, int z);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0) { // 입력 종료
			break;
		}

		// 각 테케 별로 초기화 
		memset(building, 0, sizeof(building));
		memset(visited, false, sizeof(visited));

		for (int i = 0;i < l; i++) {
			for (int j = 0;j < r;j++) {
				for (int k = 0;k < c;k++) {
					char cur_element;
					cin >> cur_element;
					if (cur_element == '#') building[i][j][k] = -1; // 벽이면
					else if (cur_element == 'S') { // 시작 좌표
						s_z = i;
						s_x = j;
						s_y = k;
					}
					else if(cur_element == 'E') { // 도착 좌표
						e_z = i;
						e_x = j;
						e_y = k;
					}
				}
			}
		} // 입력 완료


		bfs();
		
	}
	return 0;
}

void bfs() {
	queue<Pos> pq;
	pq.push(Pos{ s_z, s_x, s_y, 0 });
	visited[s_z][s_x][s_y] = true;

	while (!pq.empty()) {

		Pos cur = pq.front();
		pq.pop();

		// 종료 조건 : 도착점이면
		if (cur.x == e_x && cur.y == e_y && cur.z == e_z) {
			cout << "Escaped in " << cur.time << " minute(s)." << "\n";
			return;
		}

		for (int i = 0;i < 6;i++) { // 6방향에 대하여 이동 확인

			// 다음 위치
			int nxt_x = cur.x + dx[i];
			int nxt_y = cur.y + dy[i];
			int nxt_z = cur.z + dz[i];

			if (is_checked(nxt_x, nxt_y, nxt_z)) { // 이동 가능할 때
				pq.push(Pos{ nxt_z, nxt_x, nxt_y, cur.time + 1 });
				visited[nxt_z][nxt_x][nxt_y] = true;
			}
		}
	}

	cout << "Trapped!" << "\n";
	return;
}

bool is_checked(int x, int y, int z) { // 범위 내에 존재, 방문 여부, 벽 아닌
	return ((-1 < z && z < l) && (-1 < x && x < r) && (-1 < y && y < c) && !visited[z][x][y] && building[z][x][y] != -1);
}