#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;

int N, M; // 헛간 수, 길의 수
vector<vector<pair<int,int>>> graph; // 인접 리스트
int dist[50001]; // 최소 여물 
void Dijkstra();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	graph.resize(N + 1);
	
	int a, b, c;
	for (int i = 0;i < M;i++) {
		cin >> a >> b >> c;
		//두 개의 헛간은 하나 이상의 길로 연결되어 있을 수도 있습니다.
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}

	// 최소 여물 초기화 
	for (int i = 1;i < N+1;i++) {
		dist[i] = INF;
	}

	Dijkstra();

	cout << dist[N];

	return 0;
}

void Dijkstra() {

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // first를 cost로 넣어야 비용에 따른 오름차순
	// 시작점 초기화 
	pq.push({0,1});
	dist[1] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue; // 이미 최소 여물 구했으면 

		for (auto p: graph[cur]) { // 현재 노드와 연결된 노드 수 만큼 

			int nxt = p.first;
			int nxt_cost = p.second;

			if (dist[nxt] > cost + nxt_cost) { // 더 작으면 갱신 
				dist[nxt] = cost + nxt_cost;
				pq.push({ dist[nxt],nxt }); // 우선순위 큐 삽입 
			}
		}
	}

}