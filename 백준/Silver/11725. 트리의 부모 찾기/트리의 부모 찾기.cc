#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N; // 노드의 개수
int parent[100001]; // 각 idx의 부모 노드 저장
vector<vector<int>> adj;
queue<int> q;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N; 

	// 루트노드는 1
	parent[1] = -1; 

	adj.resize(N + 1); // 1 ~ N 까지의 노드 초기화

	int a, b;
	for (int i = 1;i < N;i++) {
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int node : adj[1]) {
		q.push(node);
		parent[node] = 1;
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int node : adj[cur]) {
			if (parent[node] == 0) {
				q.push(node);
				parent[node] = cur;
			}
		}
	}
	

	for (int i = 2;i <= N;i++) {
		cout << parent[i] << "\n";
	}
	return 0;
}