#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<bool> check; 
bool isCycle = false;
int tree_cnt = 0;

void DFS(int cur, int prev);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, tc = 1; // 정점의 개수, 간선의 개수
	while (1) {
		cin >> n >> m;

		if (n == 0 && m == 0) break; // 종료 조건

		tree_cnt = 0;

		adj.resize(n + 1); // 노드 1 ~ N 초기화
		check.assign(n + 1, false); // 노드 방문 체크 (사이클 여부)

		int a, b;
		
		for (int i = 0;i < m;i++) { // 두 정점의 간선 
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		// 노드 1 부터 n까지 확인
		for (int i = 1;i <= n;i++) {
			if (!check[i]) { // 아직 방문 안했으면
				isCycle = false;
				DFS(i, 0);

				if (!isCycle) tree_cnt++;
			}
		}

		if (tree_cnt == 0) cout << "Case " << tc << ": " << "No trees." << "\n";
		else if (tree_cnt == 1) cout << "Case " << tc << ": " << "There is one tree." << "\n";
		else cout << "Case " << tc << ": " << "A forest of " << tree_cnt << " trees." << "\n";

		tc++;
		adj.clear();
		check.clear();
	}

	return 0;
}

void DFS(int cur, int prev) {

	check[cur] = true; // 현재 노드 확인

	if (adj[cur].size() == 0) return; // 현재 노드와 더 연결된 노드 없으면 

	for (int node : adj[cur]) {
		if (check[node]) { // 이미 방문했으면

			if (node != prev) { // 직전에 확인했던 노드가 아니면 사이클임!
				isCycle = true;
			}
			continue;
		}

		DFS(node, cur);
	}
	
}