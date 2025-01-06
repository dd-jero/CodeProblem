#include <iostream>
using namespace std;
const int INF = 1e9;

int N, M; // 도시 개수, 버스 개수
int graph[1001][1001]; // 인접 행렬
int dist[1001]; // 최소 비용
bool visited[1001]; // 방문 체크 
int FindShortestNode();
void Dijkstra(int start, int end);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	// 그래프 초기화 
	for (int i = 1;i < N + 1;i++) {
		for (int j = 1;j < N + 1;j++) {
			if (i != j) graph[i][j] = INF;
		}
	}

	int src, dest, cost;
	for (int i = 0;i < M;i++) {
		cin >> src >> dest >> cost;
		graph[src][dest] = min(graph[src][dest], cost); // 최소 비용으로 저장해야함 
	}

	// 출발 도시와 도착 도시 입력 
	int start, end;
	cin >> start >> end;

	// 도시 개수 만큼 INF로 초기화 
	for (int i = 1;i < N + 1;i++) {
		dist[i] = INF;
	}

	// 인접 행렬 활용 다익스트라 
	Dijkstra(start, end);

	cout << dist[end];

	return 0;
}

// 방문하지 않는 점들 중에서 가장 가까운 점 인덱스 반환 
int FindShortestNode() {
	int min_dist = INF;
	int min_idx = -1;

	for (int i = 1;i < N + 1;i++) {
		if (visited[i]) continue;

		if (dist[i] < min_dist) {
			min_dist = dist[i];
			min_idx = i;
		}
	}
	return min_idx;
}

void Dijkstra(int start, int end) {

	// 시작점 세팅
	dist[start] = 0;
	visited[start] = true;

	// 시작점에서 연결된 노드를 확인 
	for (int i = 1;i < N + 1;i++) {
		if (graph[start][i] != INF) {
			dist[i] = graph[start][i];
		}
	}

	for (int i = 0;i < N-1;i++) {

		int cur = FindShortestNode();
		if (cur == -1) break; // 다 방문 했으면 
		visited[cur] = true;

		for (int j = 1;j < N + 1;j++) {
			if (visited[j]) continue;

			// 새로 고려하는 거리가 더 작으면 갱신
			if (dist[j] > dist[cur] + graph[cur][j]) {
				dist[j] = dist[cur] + graph[cur][j];
			}
		}

	}

}

