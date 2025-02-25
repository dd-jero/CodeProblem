#include <iostream>
using namespace std;

int Find(int x);
void Union(int x, int y);
bool IsUnion(int x, int y);

int parent[500001]; // 루트 노드 저장 배열 
int n, m, a, b;
int res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> n >> m; // 점의 개수, 진행 차례의 수

	// 자기 자신을 루트로 초기화 
	for (int i = 1;i <= n;i++) {
		parent[i] = i;
	}

	for (int i = 1;i <= m;i++) {
		cin >> a >> b;

		// 동일 집합인지 먼저 확인 => 연결 후에는 다른 트리가 될 수 도 있어서 
		if (IsUnion(a, b)) { 
			res = i;
			break;
		}

		Union(a, b);
	}

	cout << res << "\n";

	return 0;
}

int Find(int x) { // 루트 노드 찾기 
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) { // 합치기
	x = Find(x);
	y = Find(y);

	if (x == y) return; // 이미 같은 집합 

	// 큰 번호가 루트 노드가 되도록 
	if (x > y) parent[y] = x; 
	else parent[x] = y;
}

bool IsUnion(int x, int y) {
	x = Find(x);
	y = Find(y);

	return x == y;
}