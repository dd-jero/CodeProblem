#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;

int tc, h, w, cnt_doc, res;
vector<vector<char>> building;
vector<vector<bool>> visited;
set<char> key;
map<char, vector<pair<int, int>>> doors; // key: 문, vaule: 문의 좌표 

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool CanStart(int x, int y);
void BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> tc;
	string str;

	for (int t = 0;t < tc;t++) {
		cin >> h >> w;

		// 빌딩과 방문 체크, 열쇠 초기화 
		building.assign(h, vector<char>(w, ' '));
		visited.assign(h, vector<bool>(w, false));
		key.clear();
		doors.clear();
		res = 0;

		cnt_doc = 0; // 지도 상에 존재하는 문서 전체 개수
		for (int i = 0;i < h;i++) {
			cin >> str;

			for (int j = 0;j < w;j++) {
				building[i][j] = str[j];

				if (str[j] == '$') cnt_doc++;
			}
		}

		cin >> str;
		if (str != "0") {
			// 이미 가지고 있는 열쇠
			for (int i = 0;i < str.length();i++) {
				key.insert(toupper(str[i])); // 대문자로 변환해서 set에 삽입
			}
		}

		BFS();

		cout << res << "\n";
	}

	return 0;
}

// 시작 가능한 위치인가
bool CanStart(int x, int y) {

	if (visited[x][y] || building[x][y] == '*') return false;

	if (building[x][y] == '.') { // 빈 공간일 때 
		visited[x][y] = true;
		return true;
	}

	if (isupper(building[x][y])) { // 문이면
		if (key.count(building[x][y])) { // 열쇠가 있으면 열 수 있음
			visited[x][y] = true;
			return true;
		}
		else {
			doors[building[x][y]].push_back({ x, y }); // 나중을 위해 저장
			return false;
		}
	}

	if (islower(building[x][y])) { // 열쇠면
		key.insert(toupper(building[x][y])); // 열쇠 삽입
		visited[x][y] = true;
		return true;
	}

	if (building[x][y] == '$') { // 문서면
		res++;
		visited[x][y] = true;
		return true;
	}

	return false;
}

void BFS() {
	queue<pair<int, int>> q;

	// 가장자리에서 시작 가능한 모든 지점을 큐에 추가
	for (int i = 0; i < h; i++) {
		if (CanStart(i, 0)) q.push({ i, 0 });
		if (CanStart(i, w - 1)) q.push({ i, w - 1 });
	}
	for (int j = 1; j < w - 1; j++) {
		if (CanStart(0, j)) q.push({ 0, j });
		if (CanStart(h - 1, j)) q.push({ h - 1, j });
	}

	while (!q.empty()) {
		auto cur = q.front();
		visited[cur.first][cur.second] = true;
		q.pop();

		for (int d = 0;d < 4;d++) {
			int nxt_x = cur.first + dx[d];
			int nxt_y = cur.second + dy[d];

			// 빌딩의 범위를 초과하거나, 이미 방문한 위치라면 무시 
			if (nxt_x < 0 || nxt_x >= h || nxt_y < 0 || nxt_y >= w) continue;
			if (visited[nxt_x][nxt_y] || building[nxt_x][nxt_y] == '*') continue;

			if (building[nxt_x][nxt_y] == '.') { // 빈 공간이면 이동 가능 
				q.push({ nxt_x, nxt_y });
				visited[nxt_x][nxt_y] = true;
			}
			else if (islower(building[nxt_x][nxt_y])) { // 열쇠 획득
				char new_key = toupper(building[nxt_x][nxt_y]);
				key.insert(new_key); // 열쇠 추가
				q.push({ nxt_x, nxt_y });
				visited[nxt_x][nxt_y] = true;

				// 저장된 문의 좌표 처리
				if (doors.count(new_key)) {
					for (auto& loc : doors[new_key]) {
						if (!visited[loc.first][loc.second]) { // 방문하지 않은 문의 좌표만 추가
							q.push(loc);
							visited[loc.first][loc.second] = true;
						}
					}
					doors.erase(new_key);
				}
			}
			else if (isupper(building[nxt_x][nxt_y])) { // 알파벳 대문자이면 열쇠 있을 때만 이동 가능 
				if (key.count(building[nxt_x][nxt_y]) == 1) {

					q.push({ nxt_x, nxt_y });
					visited[nxt_x][nxt_y] = true;
				}
				else { // 나중에 키를 발견하면 이전에 열지 못했던, 방문 가능한 문의 위치를 활용할 수 있도록
					doors[building[nxt_x][nxt_y]].push_back({ nxt_x, nxt_y });
				}
			}
			else if (building[nxt_x][nxt_y] == '$') { // 문서이면
				q.push({ nxt_x, nxt_y });
				visited[nxt_x][nxt_y] = true;
				res++;

				if (res == cnt_doc) return;
			}

		}

	}

}