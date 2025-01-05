#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 무한대 값 정의 (INT_MAX 대신 1e9 사용하여 오버플로우 방지)
const int INF = 1e9;

int N, M; // N: 도시의 개수, M: 버스의 개수
vector<vector<pair<int, int>>> graph; // 인접 리스트로 그래프 표현
vector<int> dist; // 최소 비용 테이블

// 다익스트라 알고리즘 함수
void dijkstra(int start, int end) {
    // 최소 힙 우선순위 큐 선언 (비용, 노드 번호)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start }); // 시작 노드 정보 우선순위 큐에 삽입
    dist[start] = 0; // 시작 노드까지의 거리는 0으로 초기화

    while (!pq.empty()) {
        int cost = pq.top().first; // 현재 노드까지의 비용
        int cur = pq.top().second; // 현재 노드 번호
        pq.pop();

        // 이미 처리된 노드라면 무시
        if (dist[cur] < cost) continue;

        // 현재 노드와 연결된 다른 인접한 노드들을 확인
        for (auto& p : graph[cur]) {
            int next = p.first; // 다음 노드 번호
            int nextCost = p.second; // 다음 노드로 가는 비용

            // 현재 노드를 거쳐서 다음 노드로 이동하는 거리가 더 짧은 경우
            if (cost + nextCost < dist[next]) {
                dist[next] = cost + nextCost; // 최단 거리 갱신
                pq.push({ dist[next], next }); // 우선순위 큐에 삽입
            }
        }
    }
}

int main() {
    // 입출력 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 도시의 개수와 버스의 개수 입력
    cin >> N >> M;

    // 그래프 초기화 (1-indexed)
    graph.resize(N + 1);
    // 최단 거리 테이블 초기화
    dist.assign(N + 1, INF);

    // 버스 정보 입력
    for (int i = 0; i < M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        graph[s].push_back({ e, c }); // s에서 e로 가는 비용 c인 간선 추가
    }

    // 출발지와 도착지 입력
    int start, end;
    cin >> start >> end;

    dijkstra(start, end);

    cout << dist[end];
    return 0;
}
