#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node {
	int x;
	int y;
};

int n, m, p, q_size; // 행,렬, 플레이어 수 
int map[1001][1001]; 
int s[1001]; // 각 플레이어별 이동 가능 칸 수 
int res_cnt[1001]; // 각 플레이어별 가진 성 수 
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<Node> q[10];

void bfs(int cur_player);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> p;

	// 각 플레이어가 이동할 수 있는 칸 수 입력 
	for (int i = 1;i <= p;i++) {
		cin >> s[i];
	}

	// 초기 맵 입력 
	string str;
	for (int i = 0;i < n;i++) {
		cin >> str;
		for (int j = 0;j < m;j++) {
			if (str[j] == '#') { // 벽이면
				map[i][j] = -1;
			}
			else if (str[j] == '.') { // 빈 공간이면
				map[i][j] = 0;
			}
			else { // 플레이어의 초기 위치면
				map[i][j] = str[j] - '0'; // char to int
				q[map[i][j]].push(Node{i,j});
				res_cnt[map[i][j]]++;
			}
		}
	}

	while (true) {
		int check_p = 0;
		for (int i = 1; i <= p; i++) {
			if (!q[i].empty()) { // 확장 가능한 경우만 BFS 호출
				bfs(i);
			}
			else {
				check_p++;
			}
		}

		// 모든 플레이어가 더 이상 확장할 수 없으면 
		if (check_p == p) break;
	}

	// 출력 
	for (int i = 1;i <= p;i++) {
		cout << res_cnt[i] << " ";
	}
	cout << "\n";

	return 0;
}

void bfs(int cur_player) {

	for (int e = 0;e < s[cur_player]; e++) { // 해당 플레이어가 이동할 수 있는 최대 수 만큼
		q_size = q[cur_player].size(); // 현재 라운드에서 확장 기준이 되는 위치 
		if (q_size == 0) return;

		for (int cnt = 0;cnt < q_size;cnt++) { // 이전 라운드에서 삽입한 정보의 개수 만큼만 돌기 
			int i = q[cur_player].front().x;
			int j = q[cur_player].front().y;
			q[cur_player].pop();

			for (int d = 0;d < 4;d++) { // 4방향 모두 확인 

				int nxt_x = i + dx[d];
				int nxt_y = j + dy[d];

				// 범위 초과나 빈 공간이 아니면 pass
				if (nxt_x < 0 || nxt_x >= n || nxt_y < 0 || nxt_y >= m) continue;
				if (map[nxt_x][nxt_y] != 0) continue;


				map[nxt_x][nxt_y] = cur_player; // 해당 플레이어의 성으로 
				q[cur_player].push(Node{ nxt_x, nxt_y });
				res_cnt[cur_player]++;
			}
		}
	}

	
}

