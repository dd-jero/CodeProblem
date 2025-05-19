#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int TC, W, H, res; // 테케 수, 빌딩의 너비 높이
vector<vector<char>> building; 
vector<vector<bool>> visited; 
queue<pair<int, int>> sg_q;
queue<pair<int, int>> fire_q;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> TC;

	for (int t = 0;t < TC;t++) {
		cin >> W >> H;
		building.resize(H, vector<char>(W));
		visited.resize(H, vector<bool>(W));

		sg_q = queue<pair<int, int>>();
		fire_q = queue<pair<int, int>>();
		res = 0;

		string str;

		for (int i = 0;i < H;i++) {
			cin >> str;

			for (int j = 0;j < W;j++) {
				building[i][j] = str[j];
				
				if (str[j] == '@') sg_q.push({ i,j }); // 상근이의 시작 위치
				else if (str[j] == '*') fire_q.push({ i,j }); // 초기 불 위치
			}
		}
		
		bool escape = BFS();
		
		if (escape) cout << res << "\n";
		else cout << "IMPOSSIBLE" << "\n";

		building.clear();
		visited.clear();

	}

	return 0;
}

bool BFS() {

	
	while (!sg_q.empty()) {

		res++; // 1초 증가 

		// 불 퍼짐
		int fire_size = fire_q.size();
		for (int i = 0;i < fire_size;i++) {
			auto cur = fire_q.front();
			fire_q.pop();

			for (int d = 0;d < 4;d++) {
				int nxt_x = cur.first + dx[d];
				int nxt_y = cur.second + dy[d];

				if (nxt_x < 0 || nxt_x >= H || nxt_y < 0 || nxt_y >= W) continue; // 범위 초과

				if (building[nxt_x][nxt_y] == '.' || building[nxt_x][nxt_y] == '@') { // 퍼질 수 있는 공간이면 
					building[nxt_x][nxt_y] = '*';
					fire_q.push({ nxt_x, nxt_y });
				}
			}
		}

		// 상근 이동
		int sg_size = sg_q.size();
		for (int i = 0;i < sg_size;i++) {
			auto cur = sg_q.front();
			sg_q.pop();
			visited[cur.first][cur.second] = true;

			for (int d = 0;d < 4;d++) {
				int nxt_x = cur.first + dx[d];
				int nxt_y = cur.second + dy[d];

				if (nxt_x < 0 || nxt_x >= H || nxt_y < 0 || nxt_y >= W) return true; // 탈출 성공

				if (building[nxt_x][nxt_y] == '.' && !visited[nxt_x][nxt_y]) { // 첫 방문인 빈 공간이면
					sg_q.push({ nxt_x, nxt_y });
					visited[nxt_x][nxt_y] = true;
				}
			}
		}

	}
	
	return false; // 탈출 불가

}