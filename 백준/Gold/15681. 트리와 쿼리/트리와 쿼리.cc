#include <iostream>
#include <vector>
using namespace std;

int N, R, Q; // 트리 정점 수, 루트 번호, 쿼리 수
vector<vector<int>> connected; // connect[i]: 정점 i와 연결된 정점들
vector<int> subsize; // subsize[i]: 정점 i의 서브트리 정점 개수 

int MakeTree(int cur_node, int parent_node);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> R >> Q;

	connected.resize(N + 1);
	subsize.resize(N + 1);

	int U, V;
	for (int i = 0;i < N-1;i++) {
		cin >> U >> V;
		connected[U].push_back(V);
		connected[V].push_back(U);
	}

	MakeTree(R, -1);

	int root;
	for (int i = 0;i < Q;i++) {
		cin >> root;
		cout << subsize[root] << "\n";
	}


	return 0;
}

int MakeTree(int cur_node, int parent_node) {

	int size = 1;

	for (int node : connected[cur_node]) { // 현재 정점과 연결된 정점들 확인

		if (node != parent_node) { // 부모가 아니면
			 size += MakeTree(node, cur_node); 
		}
	}

	subsize[cur_node] = size;

	return size;
}
