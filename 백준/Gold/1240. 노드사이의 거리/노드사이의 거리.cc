#include <iostream>
#include <queue>
using namespace std;

int N, M, res = 0;// 노드 개수, 알고 싶은 노드 쌍 수 
int dis[1001][1001];
bool visited[1001];

void DFS(int cur, int end, int dist);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	int a, b, d;

	// 거리 입력
	for (int i = 0;i < N-1;i++) {
		cin >> a >> b >> d;

		if (dis[a][b] == 0) {
			dis[a][b] = d;
			dis[b][a] = d;
		}
		else {
			int min_d = dis[a][b] > d ? d : dis[a][b];
			dis[a][b] = min_d;
			dis[b][a] = min_d;
		}
	}

	// 노드 쌍 입력 
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		DFS(a, b, 0);
		cout << res << "\n";
		res = 0;

		for (int i = 1;i <= N;i++) {
			visited[i] = false;
		}
	}

	return 0;
}

void DFS(int cur, int end, int dist) {
	visited[cur] = true;
	
	if (cur == end) {
		res = dist;
		return;
	}

	for (int i = 1;i <= N;i++) {
		if (dis[cur][i] != 0) { // 연결되어 있으면
			if (!visited[i]) {

				DFS(i, end, dist + dis[cur][i]);
			}
		}
	}
	
}