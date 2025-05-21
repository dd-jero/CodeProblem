#include <iostream>
#include <vector>
using namespace std;

int N, M, res = 0; // 뉴런 개수, 시냅스 개수
vector<int> parent;

int Find(int x);
void Union(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	parent.resize(N + 1);

	for (int i = 1;i <= N;i++) {
		parent[i] = i;
	}

	int u, v;
	for (int i = 0;i < M;i++) {
		cin >> u >> v;

		if (Find(u) == Find(v)) res++; // 루트가 같으면 싸이클 존재 => 끊기
		else { // 같은 트리로 만들기 
			Union(u, v);
		}
	}

	// 부모가 자기 자신인 노드 => 합치기 
	for (int i = 1;i <= N;i++) {
		if (parent[i] == i) res++;
	}

	cout << res - 1 << "\n";

	return 0;
}

int Find(int x) {
	if (x == parent[x]) return x; // 루트 노드 리턴 
	return parent[x] = Find(parent[x]); // 경로 압축 
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) return; // 이미 같은 트리

	// 더 작은 수를 부모 노드로 약속
	if (x < y) parent[y] = x;
	else parent[y] = x;
}