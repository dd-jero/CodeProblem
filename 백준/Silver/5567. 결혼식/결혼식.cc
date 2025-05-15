#include <iostream>
#include <vector>
using namespace std;

int N, M, res = 0; // 동기 수, 리스트 길이
vector<vector<int>> adj;
vector<int> check;

void CHECK();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	adj.resize(N+1);
	check.resize(N + 1);

	int a, b;

	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	CHECK();

	cout << res << "\n";

	return 0;
}

void CHECK() {

	check[1] = true;

	// 상근이 친구의 친구까지만 초대 
	for (int nxt: adj[1]) {
		if (!check[nxt]) {
			check[nxt] = true;
			res++;
		}

		for (int nxtnxt : adj[nxt]) {
			if (!check[nxtnxt]) {
				check[nxtnxt] = true;
				res++;
			}
		}
	}
	
}