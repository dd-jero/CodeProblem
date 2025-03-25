#include <iostream>
#include <vector>
using namespace std;

int N, removeNode, root;
vector<int> parent;         // 각 노드의 부모를 저장
vector<vector<int>> child;  // 각 노드의 자식들을 저장
vector<bool> visited;       // 삭제된 노드를 방문 처리

void dfs(int node);         // 삭제된 노드와 자손들을 방문
int countLeafNodes(int node); // 리프 노드 개수 계산

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    parent.resize(N);
    child.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < N; i++) {
        cin >> parent[i];
        if (parent[i] == -1) root = i;  // 루트 노드 설정
        else child[parent[i]].push_back(i);  // 부모-자식 관계 구성
    }

    cin >> removeNode;

    // 삭제된 노드와 그 자손을 방문 처리
    dfs(removeNode);

    // 루트가 삭제되었으면 리프는 0개
    if (visited[root]) {
        cout << 0 << "\n";
        return 0;
    }

    // 리프 노드 개수 계산
    int leafCount = countLeafNodes(root);
    cout << leafCount << "\n";

    return 0;
}

// DFS로 삭제된 노드와 모든 자손을 방문 처리
void dfs(int node) {
    visited[node] = true;
    for (int childNode : child[node]) {
        dfs(childNode);
    }
}

// 리프 노드 개수를 계산하는 함수
int countLeafNodes(int node) {
    if (visited[node]) return 0;  // 삭제된 노드는 제외

    bool hasValidChild = false;
    int count = 0;

    for (int childNode : child[node]) {
        if (!visited[childNode]) {     // 유효한 자식이 있는지 확인
            hasValidChild = true;
            count += countLeafNodes(childNode);
        }
    }

    if (!hasValidChild) return 1;      // 유효한 자식이 없으면 리프

    return count;
}
