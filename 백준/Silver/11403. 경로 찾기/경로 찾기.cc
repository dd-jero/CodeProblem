#include <iostream>
using namespace std;

int N, adj[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> adj[i][j];
		}
	}

	for (int k = 1;k <= N;k++) { // 중간 정점
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (adj[i][k] && adj[k][j]) { // 정점 i에서 정점 k를 거쳐 정점 j에 연결되어 있는지 
					adj[i][j] = 1;
				}
			}
		}
	}
	

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

