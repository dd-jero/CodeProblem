#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, arr[301][301], melt_cnt[301][301], res = 0, cnt_zero = 0; // 행,열
bool visited[301][301];
bool finish;
queue<pair<int, int>> ice_location;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void Melt(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {

		int cnt = 0; // 영역의 개수
		int cnt_zero = 0; // 0의 개수 

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {

				if (arr[i][j] == 0) cnt_zero++;

				if (arr[i][j] > 0 && !visited[i][j]) {
					cnt++;

					if (cnt >= 2) { // 분리됨을 의미 
						finish = true;
						break;
					}

					Melt(i,j);
				}
			}

			if (finish) break;
		}
		 
		if (finish) { // 정상적으로 분리된 경우 
			cout << res << "\n";
			break; 
		}
		
		if (cnt_zero == N*M) { // 분리되지 않고 다 녹은 경우
			cout << 0 << "\n";
			break; 
		}

		res++;

		// 초기화 
		memset(melt_cnt, 0, sizeof(melt_cnt));
		memset(visited, false, sizeof(visited));
	}

	return 0;
}

void Melt(int x, int y) { // 1년 녹이기 

	ice_location.push({ x,y });
	visited[x][y] = true;

	while (!ice_location.empty()) {
		auto cur = ice_location.front();
		ice_location.pop();

		for (int d = 0;d < 4;d++) {
			int nxt_x = cur.first + dx[d];
			int nxt_y = cur.second + dy[d];

			if (nxt_x < 0 || nxt_x >= N || nxt_x < 0 || nxt_y >= M) continue; // 범위 초과
			if (visited[nxt_x][nxt_y]) continue; // 이미 방문 했으면

			if (arr[nxt_x][nxt_y] > 0) { // 주변이 빙산이면
				ice_location.push({ nxt_x,nxt_y });
				visited[nxt_x][nxt_y] = true;
			}
			else { // 주변이 0이면
				melt_cnt[cur.first][cur.second]++;
			}
		}
	}
		
	// 1년치 한번에 녹이기
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (melt_cnt[i][j] > 0) {
				arr[i][j] -= melt_cnt[i][j];
				arr[i][j] = arr[i][j] < 0 ? 0 : arr[i][j];
			}
		}
	}
}


