#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int virus;
	int x;
	int y;

	bool operator<(const Node& other) const {
		return this->virus > other.virus;
	}
};

int N, K, S, X, Y; // 시험관 크기, 바이러스 종류, 시간, 최종 위치
int arr[201][201];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

priority_queue<Node> pq;

void BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> arr[i][j];

			if (arr[i][j] != 0) {
				pq.push(Node{ arr[i][j], i,j });
			}
		}
	}

	cin >> S >> X >> Y;

	BFS();

	cout << arr[X][Y] << "\n";

	return 0;
}

void BFS() {

	for(int s=1; s<=S; s++) { // S초 지난 후에 결과를 확인하기 위함.
		priority_queue<Node> tmp;

		while(!pq.empty()) { // 현재 시간에서의 바이러스로
			Node cur = pq.top();
			pq.pop();

			for (int d = 0;d < 4;d++) {
				int nxt_x = cur.x + dx[d];
				int nxt_y = cur.y + dy[d];

				if (nxt_x<1 || nxt_x>N || nxt_y<1 || nxt_y>N) continue; // 범위를 초과하면
				if (arr[nxt_x][nxt_y] != 0) continue; // 이미 다른 바이러스가 존재하면

				arr[nxt_x][nxt_y] = cur.virus;
				tmp.push(Node{ cur.virus, nxt_x, nxt_y });
			}

		}

		while (!tmp.empty()) {
			Node t = tmp.top();
			tmp.pop();

			pq.push(t);
		}
	}

}