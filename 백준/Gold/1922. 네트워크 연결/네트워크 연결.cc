#define INF 2e9
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
	int next;
	int cost;

	bool operator<(const Node& other) const { // 비용에 따른 오름차순 우선순위 큐 위함.
		return this->cost > other.cost;
	}

	void print() const {
		cout << "Next: " << next << ", Cost: " << cost << endl;
	}
};

int n, m, a, b, c, sum = 0; // pc 수, 연결 수, a와 b pc간의 비용 c
vector<vector<Node>> graph;
priority_queue<Node> pq; // 기본이 최대힙
bool visited[1001] = { false };
void prim();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	graph.resize(n + 1);

	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;

		// 양방향
		graph[a].push_back(Node{ b,c });
		graph[b].push_back(Node{ a,c });
	}

	prim();

	cout << sum << "\n";

	return 0;
}

void prim() {

	pq.push(Node{ 1,0 }); // 1번 컴터부터 시작
	
	while (!pq.empty()) {
		Node cur = pq.top();
		pq.pop();

		int next_pc = cur.next;
		int cur_cost = cur.cost;

		if (visited[next_pc]) continue; // 이미 최소 비용 결정 되었으면 

		visited[next_pc] = true;
		sum += cur_cost;

		for (const auto& neighbor : graph[next_pc]) { // 현재 pc와 연결된 pc를 고려 
			if (!visited[neighbor.next]) {
				pq.push(neighbor);
			}
		}
	}
}