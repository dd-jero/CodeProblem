#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, res = 0;// 노드 개수, 알고 싶은 노드 쌍 수 
vector<vector<pair<int, int>>> dis;
vector<bool> visited; 

void DFS(int cur, int end, int dist);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	dis.resize(N + 1);
	visited.resize(N + 1);

	int a, b, d;

	// 거리 입력
	for (int i = 0;i < N-1;i++) {
		cin >> a >> b >> d;
		
		// {노드, 거리}
		dis[a].push_back({ b,d }); 
		dis[b].push_back({ a,d });

	}

	// 노드 쌍 입력 
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		DFS(a, b, 0);
		cout << res << "\n";
		res = 0;

		visited.clear();
		visited.assign(N + 1, false);
	}

	return 0;
}

void DFS(int cur, int end, int dist) {
	visited[cur] = true;
	
	if (cur == end) {
		res = dist;
		return;
	}

	for (auto nxt: dis[cur]) {
		if (!visited[nxt.first]) { 
			DFS(nxt.first, end, dist + nxt.second);
		}
	}
	
}