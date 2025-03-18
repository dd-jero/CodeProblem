#define INF 2e9
#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
using namespace std;

int N, M, res = INF; // 연구소 크기, 놓을 수 있는 바이러스 수, 최소 시간 
int arr[51][51], lab[51][51], visited[51][51]; 
vector<pair<int, int>> virus;
vector<bool> on_virus;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void INIT();
void START(int idx, int cnt);
void BFS();
bool CHECK(); // 빈 칸 존재 확인

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	int num;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> num;
			
			if (num == 2) { // 바이러스
				arr[i][j] = -2;
				virus.push_back({ i,j }); // 바이러스 위치 삽입 
			}
			else if (num == 1) { // 벽
				arr[i][j] = -1;
			}
			else { // 빈 칸
				arr[i][j] = 0;
			}
		}
	}

	on_virus.resize(virus.size(), false);
	START(0, 0);

	if (res == INF) cout << -1 << "\n";
	else cout << res << "\n";

	return 0;
}

void START(int idx, int cnt) { // 비활성 바이러스의 M 크기 조합 

	// 종료 조건: BFS 시작
	if (cnt == M) {

		INIT(); 
		BFS();
	}

	for (int i = idx;i < virus.size(); i++) {

		// 해당 바이러스 활성화
		on_virus[i] = true;
		arr[virus[i].first][virus[i].second] = -3; // 활성 바이러스와 구분 위함

		START(i + 1, cnt + 1);

		// 원상 복구
		on_virus[i] = false;
		arr[virus[i].first][virus[i].second] = -2;


	}
}


void BFS() {
	queue<pair<int, int>> q;

	// 활성화된 바이러스 위치 삽입
	for (int i = 0;i < virus.size();i++) {
		if (on_virus[i]) q.push({ virus[i].first, virus[i].second });
	}

	// 1초씩 진행
	int time = 1; 

	while (!q.empty()) 
	{
		int q_size = q.size();

		for (int i = 0;i < q_size;i++) {
			auto cur = q.front();
			q.pop();
			visited[cur.first][cur.second] = true;

			// 상하좌우 빈칸 동시에 복제됨.
			for (int d = 0;d < 4;d++) {
				int nxt_x = cur.first + dx[d];
				int nxt_y = cur.second + dy[d];

				if (nxt_x < 0 || nxt_x >= N || nxt_y < 0 || nxt_y >= N) continue; // 범위 초과
				if (visited[nxt_x][nxt_y]) continue; // 이미 방문했으면 

				if (lab[nxt_x][nxt_y] == 0) { // 빈 칸이면 
					lab[nxt_x][nxt_y] = time;
					visited[nxt_x][nxt_y] = true;
					q.push({ nxt_x,nxt_y });
				}
				else if (lab[nxt_x][nxt_y] == -2) { // 비활성 바이러스 이면
					lab[nxt_x][nxt_y] = 0;
					visited[nxt_x][nxt_y] = true;
					q.push({ nxt_x,nxt_y });
				}

			}

		}
		
		time++;
	}

	if (CHECK()) { // 바이러스가 모두 퍼졌으면 다시 조합 
		res = res > time ? time : res;
		return;
	}
}

void INIT() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			lab[i][j] = arr[i][j];
			visited[i][j] = false;
		}
	}
}

bool CHECK() {

	int tmp_time = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (lab[i][j] == 0 && !visited[i][j]) { // 빈칸이면서 방문안했으면
				return false;
			}

			if (lab[i][j] != -1 && lab[i][j] != -2 && lab[i][j] != -3) tmp_time = tmp_time < lab[i][j] ? lab[i][j] : tmp_time;
		}
	}

	// 모든 칸에 퍼뜨렸으면
	res = res > tmp_time ? tmp_time : res;
	return true;
}