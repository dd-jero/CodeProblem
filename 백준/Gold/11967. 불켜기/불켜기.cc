#include <iostream>
#include <queue>
#include <map>
using namespace std;

int N, M, res = 0; // 방 크기, M줄의 정보
bool room[101][101]; // 0: 꺼짐, 1: 켜짐
bool visited[101][101]; // 방문체크
vector<pair<int,int>> vec;
map<pair<int, int>, vector<pair<int,int>>> check; // key에 해당하는 좌표에 불을 킬 수 있는 value 좌표 

int dx[4] = {0,0,-1,1};
int dy[4] = { 1,-1,0,0 };

void BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	int x, y, a, b;
	for (int i = 0;i < M;i++) {
		cin >> x >> y >> a >> b;
		check[{x, y}].push_back({ a,b });
	}

	room[1][1] = true; // 출발 위치

	BFS();

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (room[i][j]) res++;
		}
	}

	cout << res << "\n";


	return 0;
}

void BFS() {
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	vec.push_back({ 1,1 });
	visited[1][1] = true;

	while (!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();

		// 해당 좌표의 스위치로 불키기
		for (int i = 0; i < check[cur].size(); i++) {
			int light_x = check[cur][i].first;
			int light_y = check[cur][i].second;
			room[light_x][light_y] = true;
		}
		
		// 이미 방문했던 위치에서의 상하좌우 중 새로운 풀 켜진 방이 존재할 수도!
		int vec_size = vec.size(); 

		for (int i = 0;i < vec_size;i++) {
			int cur_x = vec[i].first;
			int cur_y = vec[i].second;

			for (int i = 0;i < 4;i++) {
				int nxt_x = cur_x + dx[i];
				int nxt_y = cur_y + dy[i];

				if (nxt_x <1 || nxt_x>N || nxt_y<1 || nxt_y>N) continue; // 방의 범위를 초과하면 무시
				if (visited[nxt_x][nxt_y]) continue; // 이미 방문했으면 

				if (room[nxt_x][nxt_y]) { // 해당 방의 불이 켜져 있으면	
					visited[nxt_x][nxt_y] = true;
					q.push(make_pair(nxt_x, nxt_y));
					vec.push_back({ nxt_x,nxt_y });
				}
			}
		}
	}

}