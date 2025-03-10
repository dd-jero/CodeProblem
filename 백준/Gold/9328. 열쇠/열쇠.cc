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
map<char, vector<pair<int, int>>> doors; // key: 문, value: 문의 좌표 

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool CanStart(int x, int y);
void BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> tc;
	string str;

	for (int t = 0; t < tc; t++) {
		cin >> h >> w;

		// 빌딩과 방문 체크, 열쇠 초기화 
		building.assign(h, vector<char>(w, ' '));
		visited.assign(h, vector<bool>(w, false));
		key.clear();
		doors.clear();
		res = 0;

		cnt_doc = 0; // 지도 상에 존재하는 문서 전체 개수
		for (int i = 0; i < h; i++) {
			cin >> str;
			for (int j = 0; j < w; j++) {
				building[i][j] = str[j];
				if (str[j] == '$') cnt_doc++; // 문서 개수 카운트
			}
		}

		cin >> str;
		if (str != "0") {
			for (char c : str) key.insert(toupper(c)); // 이미 가진 열쇠 추가
		}

		BFS();
		cout << res << "\n";
	}

	return 0;
}

// 시작 가능한 위치인가
bool CanStart(int x, int y) {
	if (visited[x][y] || building[x][y] == '*') return false; // 벽이면 시작 불가능

	if (building[x][y] == '.' || building[x][y] == '$') { // 빈 공간 또는 문서면 이동 가능
		visited[x][y] = true;
		if (building[x][y] == '$') res++; // 문서 획득
		return true;
	}

	if (islower(building[x][y])) { // 열쇠면
		key.insert(toupper(building[x][y])); // 열쇠 삽입
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

	// 초기 열쇠로 열 수 있는 문 미리 처리
	for (auto it = doors.begin(); it != doors.end(); ) {
		if (key.count(it->first)) { // 이미 열쇠를 가지고 있다면
			for (auto& loc : it->second) {
				q.push(loc);
				visited[loc.first][loc.second] = true;
			}
			it = doors.erase(it); // 사용한 문은 삭제
		}
		else {
			++it;
		}
	}

	while (!q.empty()) {
		int cur_x  = q.front().first;
		int cur_y = q.front().second;

		q.pop();

		for (int d = 0; d < 4; d++) {
			int nxt_x = cur_x + dx[d];
			int nxt_y = cur_y + dy[d];

			// 빌딩 범위 초과 or 이미 방문한 곳이면 무시
			if (nxt_x < 0 || nxt_x >= h || nxt_y < 0 || nxt_y >= w) continue;
			if (visited[nxt_x][nxt_y]) continue;
			if (building[nxt_x][nxt_y] == '*') continue; // 벽이면 무시

			if (building[nxt_x][nxt_y] == '.' || building[nxt_x][nxt_y] == '$') { // 빈 공간 or 문서
				if (building[nxt_x][nxt_y] == '$') res++;
				q.push({ nxt_x, nxt_y });
				visited[nxt_x][nxt_y] = true;
			}
			else if (islower(building[nxt_x][nxt_y])) { // 열쇠 발견
				char new_key = toupper(building[nxt_x][nxt_y]);
				key.insert(new_key);
				q.push({ nxt_x, nxt_y });
				visited[nxt_x][nxt_y] = true;

				// 해당 열쇠로 열 수 있는 문들 방문 처리
				if (doors.count(new_key)) {
					for (auto& loc : doors[new_key]) {
						q.push(loc);
						visited[loc.first][loc.second] = true;
					}
					doors.erase(new_key);
				}
			}
			else if (isupper(building[nxt_x][nxt_y])) { // 문 발견
				if (key.count(building[nxt_x][nxt_y])) { // 열쇠가 있으면 열기
					q.push({ nxt_x, nxt_y });
					visited[nxt_x][nxt_y] = true;
				}
				else { // 열쇠가 없으면 저장
					doors[building[nxt_x][nxt_y]].push_back({ nxt_x, nxt_y });
				}
			}
		}
	}
}
