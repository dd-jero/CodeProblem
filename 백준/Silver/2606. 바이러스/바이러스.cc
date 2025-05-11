#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, res = 0; // 컴퓨터 수, 직접 연결된 컴퓨터 쌍 수 
vector<vector<int>> adj;
vector<bool> visited;

void BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	adj.resize(N + 1);
	visited.resize(N + 1);

	int a, b;
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	BFS();

	cout << res << "\n";

	return 0;
}

void BFS() {
	queue<int> q;

	// 1번 바이러스 감염
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int node : adj[cur]) {
			if (!visited[node]) {
				q.push(node);
				visited[node] = true;
				res++;
			}
		}
	}

}