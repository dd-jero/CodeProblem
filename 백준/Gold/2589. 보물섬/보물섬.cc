#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
	int x;
	int y;
	int time;

	bool operator<(const Node& other) const {
		return this->time > other.time;
	}
};

int N, M, res = 0; //세로, 가로 크기
char map[51][51];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool visited[51][51];

void BFS(Node start);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	string str;
	for (int i = 0;i < N;i++) {
		cin >> str;

		for (int j = 0;j < M;j++) {
			map[i][j] = str[j];
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (map[i][j] == 'L') {
				BFS(Node{i,j,0});
				memset(visited, 0, sizeof(visited)); // 새로운 출발점에서 시작 위함. 
			}
		}
	}

	cout << res << "\n";

	return 0;
}


void BFS(Node start) {
	priority_queue<Node> pq;
	pq.push(start);
	visited[start.x][start.y] = true;

	while (!pq.empty()) {
		Node cur = pq.top();
		pq.pop();

		res = res < cur.time ? cur.time : res;

		for (int d = 0;d < 4;d++) {
			int nxt_x = cur.x + dx[d];
			int nxt_y = cur.y + dy[d];

			if (nxt_x < 0 || nxt_x >= N || nxt_y < 0 || nxt_y >= M) continue; // 범위 초과
			if (visited[nxt_x][nxt_y] || map[nxt_x][nxt_y] == 'W') continue; // 이미 방문 했거나 바다이면 

			pq.push(Node{ nxt_x, nxt_y, cur.time + 1 });
			visited[nxt_x][nxt_y] = true;
			
		}
	}

}