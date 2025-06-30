#include <iostream>
#include <queue>
using namespace std;

int N, K, res; // 수빈 시작 위치, 동생 위치 
bool visited[100001]; // 위치 방문 체크

void BFS(int start, int end);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	BFS(N, K);
	cout << res << "\n";

	return 0;
}

void BFS(int start, int end) {
	queue<pair<int, int>> q; // 해당 위치 오는데 걸린 시간, 해당 위치 
	q.push({ 0, start });
	visited[start] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		int nxt_loc, cost;
		for (int d = 0;d < 3;d++) {
			if (d == 0) { // 0초후 2*X
				nxt_loc = cur.second * 2;
				cost = cur.first;
			}
			else if (d == 1) {  // 1초후 X-1
				nxt_loc = cur.second - 1;
				cost = cur.first + 1;
				
			}
			else { // 1초후 X+1
				nxt_loc = cur.second + 1;
				cost = cur.first + 1;
			}

			if (nxt_loc < 0 || nxt_loc > 100000) continue;
			if (visited[nxt_loc]) continue;

			if (nxt_loc == end) {
				res = cost;
				return; // 동생을 찾는 가장 빠른 시간 
			}

			q.push({ cost, nxt_loc });
			visited[nxt_loc] = true;
		}
	}

}