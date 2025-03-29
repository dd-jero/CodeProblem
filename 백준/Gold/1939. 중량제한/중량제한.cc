#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A, B, C, X, Y;
int res = 0; // 한번의 이동으로 옮길 수 있는 최대 중량 
bool flag;

vector<vector<pair<int,int>>> adj; // 인접 행렬 
void BFS(int weight); // 이분 탐색으로 결정한 중량으로 시작 섬에서 도착 섬까지 BFS
void BinarySearch(); // 중량에 대한 이분 탐색

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M; // 섬의 개수, 다리 개수

	adj.resize(N + 1); // 인접 행렬 초기화 

	for (int i = 0;i < M;i++) {
		cin >> A >> B >> C; // A섬과 B섬 사이의 중량제한 C인 다리

		adj[A].push_back({ B,C });
		adj[B].push_back({ A,C });
	}

	cin >> X >> Y; // 공장이 있는 두 섬

	BinarySearch();

	cout << res << "\n";

	return 0;
}

void BFS(int weight) {
	vector<int> visited(N + 1, false); // 섬 방문 체크 
	queue<int> q;

	// 시작점 
	q.push(X);
	visited[X] = true;
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		// 도착 점이면
		if (cur == Y) {
			res = res < weight ? weight : res; // 현재 기준 중량과 비교 갱신 
			flag = true;
		}

		// 연결된 섬 확인 
		for (auto i : adj[cur]) {
			// 아직 방문 안했고, 현재 기준 중량보다 크거나 같아야함
			if (!visited[i.first] && i.second >= weight) {
				q.push(i.first);
				visited[i.first] = true;
			}
		}
	}

}

void BinarySearch() {
	int left = 1;
	int right = 1e9;

	while (left <= right) {
		int mid = (left + right) / 2; 

		flag = false; // 도착 점 방문 가능 여부 
		BFS(mid);

		if (flag) left = mid + 1;
		else right = mid - 1;
	}
}