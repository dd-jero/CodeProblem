#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

int n, m, cnt = 0, total_b = 0, total_w = 0; // 가로, 세로 크기, 현재 같은 인접 병사 수, 파란색 위력합, 흰색 위력합
char soilder;
int dx[4] = {0,0,1,-1};
int dy[4] = { 1,-1,0,0 };
vector<vector<char>> war;
vector<vector<bool>> checked;
queue<pair<int, int>> q;
void bfs(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	war.resize(m, vector<char>(n));
	checked.resize(m, vector<bool>(n, false));

	string str;
	for (int i = 0;i < m;i++) {

		cin >> str;
		for (int j = 0;j < n;j++) {
			war[i][j] = str[j];
		}
	} // 입력 완료

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (!checked[i][j]) { // 해당 좌표 방문하지 않았으면
				soilder = war[i][j]; 
				cnt = 1;
				bfs(i, j); 

				// 큐가 비어서 나오게 되면 
				if (soilder == 'B') total_b += pow(cnt, 2);
				else total_w += pow(cnt, 2);

			}
		}
	}

	cout << total_w << " " << total_b;

	return 0;
}

void bfs(int x, int y) {
	q.push(make_pair(x, y)); // 현재 좌표 삽입
	checked[x][y] = true;


	while (!q.empty()) {

		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nxt_x = cur_x + dx[i];
			int nxt_y = cur_y + dy[i];

			if (( - 1 < nxt_x && nxt_x < m) && ( - 1 < nxt_y && nxt_y < n)) { // 범위 내에 존재할 때
				if (!checked[nxt_x][nxt_y] && soilder == war[nxt_x][nxt_y]) { // 체크하지 않았고, 같은 나라 병사이면
					q.push(make_pair(nxt_x, nxt_y)); // 큐 삽입
					checked[nxt_x][nxt_y] = true;
					cnt++; // 병사수 증가
				}
			}
		}
	}
}