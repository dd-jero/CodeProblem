#include <iostream>
#include <vector>
using namespace std;

int N, R, Q; // 트리 정점 수, 루트 번호, 쿼리 수
vector<vector<int>> tree;
vector<vector<int>> childnode; // i 노드의 child 
vector<int> subtree_size; // 해당 i 노드의 서브 트리 노드 수

void MakeTree(int cur_node, int parent); 
void CountSubtreeNodes(int node);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> R >> Q;
	tree.resize(N+1);
	childnode.resize(N + 1);
	subtree_size.resize(N + 1, 0);

	int s, e;
	for (int i = 1;i < N;i++) {
		cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	MakeTree(R, -1);
	CountSubtreeNodes(R);

	int q;
	for (int i = 0;i < Q;i++) {
		cin >> q; // 해당 정점을 루트로
		
		cout << subtree_size[q] << "\n";
	}

	return 0;
}

void MakeTree(int cur_node, int parent) {
	for (int node : tree[cur_node]) { // 현재 노드와 연결된 노드 확인
		if (node != parent) { // 부모 노드 아니면
			childnode[cur_node].push_back(node); // 자식 노드로 삽입
			MakeTree(node, cur_node); // 현재 노드를 부모로 하는 자식 노드의 트리 구성 
		}
	}
}

void CountSubtreeNodes(int node) {
	subtree_size[node] = 1; // 현재 노드를 포함

	for (int n : childnode[node]) {
		CountSubtreeNodes(n); // 현재 노드의 자식 노드의 서브 트리 노드 수 구하기 
		subtree_size[node] += subtree_size[n];
	}
}